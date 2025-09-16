#include <iostream>
#include <iomanip>
#include <string>

// Enum for Book Genre
enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };

// Global array of genre names
const std::string GenreNames[] = {"Fiction", "Non-Fiction", "Science", "History", "Technology"};

std::string getGenreName(Genre g) {
    if (g >= FICTION && g <= TECHNOLOGY) {
        return GenreNames[g];  // valid genre
    }
    return "Unknown"; // fallback for invalid values
}

// Book Class
class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus; // 'A' = Available, 'B' = Borrowed
    bool isReferenceOnly;
    std::string title;
    Genre genre;

public:
    // Default constructor
    Book()
        : bookID(0), rating(0.0), price(0.0), availabilityStatus('A'),
          isReferenceOnly(false), title("Untitled"), genre(FICTION) {}

    // Parameterized constructor
    Book(int id, float r, double p, char status, bool ref, const std::string &t, Genre g)
        : bookID(id), rating(r), price(p), availabilityStatus(status),
          isReferenceOnly(ref), title(t), genre(g) {}

    // Destructor
    ~Book() {
        std::cout << "Book object with ID " << bookID << " destroyed.\n";
    }

    // Getters
    int getBookID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getAvailabilityStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    std::string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

    // Setters
    void setBookID(int id) { bookID = id; }
    void setRating(float r) { rating = r; }
    void setPrice(double p) { price = p; }
    void setAvailabilityStatus(char s) { availabilityStatus = s; }
    void setIsReferenceOnly(bool ref) { isReferenceOnly = ref; }
    void setTitle(const std::string &t) { title = t; }
    void setGenre(Genre g) { genre = g; }

    // Update availability
    void updateAvailability(bool isBorrowed) {
        availabilityStatus = isBorrowed ? 'B' : 'A';
    }

    // Display book details
    void displayDetails() const {
        std::cout << "\n--- Book Details ---\n";
        std::cout << "ID: " << bookID << "\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Price: " << price << "\n";
        std::cout << "Rating: " << rating << "\n";
        std::cout << "Availability Status: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << "\n";
        std::cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << "\n";
        std::cout << "Genre: " << getGenreName(genre) << "\n";
    }
};

// Global Functions
void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);
    if (book.getIsReferenceOnly()) {
        std::cout << "Book ID " << book.getBookID() << " marked as reference-only.\n";
    }
}

bool isAffordable(const Book &book, const double budget) {
    return book.getPrice() <= budget;
}

void printFormattedBookList(const Book books[], const int size) {
    std::cout << "\nID  | Title               | Price   | Rating | Status   | Reference | Genre\n";
    std::cout << "----------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(4) << books[i].getBookID()
                  << "| " << std::setw(30) << books[i].getTitle()
                  << "| " << std::setw(8) << books[i].getPrice()
                  << "| " << std::setw(6) << books[i].getRating()
                  << "| " << std::setw(8) << (books[i].getAvailabilityStatus() == 'A' ? "Available" : "Borrowed")
                  << "| " << std::setw(9) << (books[i].getIsReferenceOnly() ? "Yes" : "No")
                  << "| " << getGenreName(books[i].getGenre()) << "\n";
    }
}

int main() {
    const int SIZE = 3;
    Book books[SIZE] = {
        Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY),
        Book(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE),
        Book() // default
    };

    int choice;
    do {
        std::cout << "\n--- Library Menu ---\n";
        std::cout << "1. Add book details\n";
        std::cout << "2. Mark a book as reference-only\n";
        std::cout << "3. Check if a book is affordable\n";
        std::cout << "4. Update availability\n";
        std::cout << "5. Display book details\n";
        std::cout << "6. Display all books\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice:";
        std::cin >> choice;

        if (std::cin.fail()) { 
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            int index;
            std::cout << "Enter index (0-2): ";
            std::cin >> index;
            if (index < 0 || index >= SIZE) {
                std::cout << "Invalid index.\n";
                continue;
            }

            int id; float rating; double price; char status; bool ref; std::string title; int g;
            std::cout << "Enter Book ID: "; std::cin >> id;
            std::cout << "Enter Title: "; std::cin.ignore(); std::getline(std::cin, title);
            std::cout << "Enter Price: "; std::cin >> price;
            std::cout << "Enter Rating (0.0–5.0): "; std::cin >> rating;
            std::cout << "Enter Status (A/B): "; std::cin >> status;
            std::cout << "Is Reference Only (0/1): "; std::cin >> ref;
            std::cout << "Enter Genre (0=FICTION,1=NONFICTION,2=SCIENCE,3=HISTORY,4=TECHNOLOGY): ";
            std::cin >> g;

            if (rating < 0.0 || rating > 5.0 || price <= 0 || title.empty() || (g < 0 || g > 4)) {
                std::cout << "Invalid input. Book not added.\n";
            } else {
                books[index] = Book(id, rating, price, status, ref, title, static_cast<Genre>(g));
                std::cout << "Book added successfully.\n";
            }
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            bool found = false;
            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    markAsReference(books[i]);
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Book ID not available.\n";
        }
        else if (choice == 3) {
            int id; double budget;
            std::cout << "Enter Book ID: "; std::cin >> id;
            std::cout << "Enter Budget: "; std::cin >> budget;
            bool found = false;
            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    std::cout << (isAffordable(books[i], budget) ? "Affordable\n" : "Not Affordable\n");
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Book ID not available.\n";
        }
        else if (choice == 4) {
            int id; bool isBorrowed;
            std::cout << "Enter Book ID: "; std::cin >> id;
            std::cout << "Is Borrowed (1=yes,0=no): "; std::cin >> isBorrowed;
            bool found = false;
            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    books[i].updateAvailability(isBorrowed);
                    std::cout << "Availability updated.\n";
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Book ID not available.\n";
        }
        else if (choice == 5) {
            int id;
            std::cout << "Enter Book ID: "; std::cin >> id;
            bool found = false;
            for (int i = 0; i < SIZE; i++) {
                if (books[i].getBookID() == id) {
                    books[i].displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Book ID not available.\n";
        }
        else if (choice == 6) {
            printFormattedBookList(books, SIZE);
        }
        else if (choice == 7) {
            std::cout << "Exiting program...\n";
        }
        else {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
