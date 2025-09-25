#ifndef POKERLOGIC_H
#define POKERLOGIC_H

#include <vector>
#include <string>
#include "Card.h"

// Returns score for a 5-card hand
int evaluateHand(const std::vector<Card>& hand);

// Converts score to string
std::string handToString(int score);

#endif
