#include <vector>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <string>

enum Severity { PRIMARY, WARN, DANGER, SUCCESS };

enum DamageType { POISON, TRAP, NONE };

struct Damage {
    int moves;
    int value;
    DamageType type;
};

enum BonusType { HEALTH, CURE };

struct Bonus {
    BonusType type;
    int value;
};

struct Vect {
    int i;
    int j;
};
