#include "PokerLogic.h"
#include <map>
#include <algorithm>

// -------------------- Poker Hand Evaluation --------------------
// Score definitions (higher score = better hand):
// 0: High Card        -> No combination, the highest card decides the hand
// 1: One Pair         -> Two cards of the same face 
// 2: Two Pair         -> Two different pairs 
// 3: Three of a Kind  -> Three cards of the same face 
// 4: Straight         -> Five consecutive cards, any suits (e.g., 5-6-7-8-9)
// 5: Flush            -> All five cards of the same suit 
// 6: Full House       -> Three of a kind plus a pair 
// 7: Four of a Kind   -> Four cards of the same face
// 8: Straight Flush   -> Straight and Flush combined (all same suit)

int evaluateHand(const std::vector<Card>& hand){
    std::map<int,int> faceCount;
    std::map<int,int> suitCount;
    std::vector<int> faces;

    // Count faces and suits
    for(const Card& c: hand){
        faceCount[c.getFace()]++;
        suitCount[c.getSuit()]++;
        faces.push_back(c.getFace());
    }

    // Check for flush (all same suit)
    bool flush = false;
    for(auto &s: suitCount) 
        if(s.second == 5) flush = true;

    // Check for straight (consecutive faces)
    std::sort(faces.begin(),faces.end());
    bool straight = true;
    for(size_t i=1;i<faces.size();i++){
        if(faces[i] != faces[i-1]+1){ straight = false; break;}
    }

    // Count duplicates for pairs, three/four of a kind
    int pairs=0, three=0, four=0;
    for(auto &f: faceCount){
        if(f.second==2) pairs++;
        if(f.second==3) three++;
        if(f.second==4) four++;
    }

    // Determine hand score
    if(straight && flush) return 8; // Straight Flush
    if(four) return 7;              // Four of a Kind
    if(three && pairs) return 6;    // Full House
    if(flush) return 5;             // Flush
    if(straight) return 4;          // Straight
    if(three) return 3;             // Three of a Kind
    if(pairs==2) return 2;          // Two Pair
    if(pairs==1) return 1;          // One Pair
    return 0;                        // High Card
}

// Convert score to string for display
std::string handToString(int score){
    switch(score){
        case 8: return "Straight Flush";
        case 7: return "Four of a Kind";
        case 6: return "Full House";
        case 5: return "Flush";
        case 4: return "Straight";
        case 3: return "Three of a Kind";
        case 2: return "Two Pair";
        case 1: return "One Pair";
        default: return "High Card";
    }
}
