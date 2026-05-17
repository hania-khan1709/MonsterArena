#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

enum power { FIRE, WATER, AIR, EARTH };

string describeElement(power p) {
    switch (p) {
        case FIRE: return "Fire";
        case WATER: return "Water";
        case AIR: return "Air";
        case EARTH: return "Earth";
        default: return "Unknown";
    }
}



string randomCommentary() {
    const string lines[] = {
        "THIS MONSTER'S GIVING MAIN CHARACTER ENERGY!!",
        "THAT HAD TO HURT!!",
        "POV: YOU'RE GETTING COOKED!",
        "THE CROWD GOES WILD!",
        "THE 1V1 IS TOO REAL RN !"
    };
    string line = lines[rand() % 5];
    string border(line.length() + 8, '=');
    string result = "\n";
    result += border;
    result += "\n||  ";
    result += line;
    result += "  ||\n";
    result += border;
    result += "\n";
    return result;
}

class MONSTER {
protected:
    string name;
    power powerr;
    int health;
    int baseDamage;
    int specialBar;
    const int maxSpecialBar = 3;

public:
    MONSTER(string n, power p, int hp, int dmg)
        : name(n), powerr(p), health(hp), baseDamage(dmg), specialBar(0) {}

    virtual ~MONSTER() {}

    string getName() const { 
        return name; 
    }
    power getPower() const { 
        return powerr; 
    }
    int getHealth() const {
        return health; 
        }
    bool isAlive() const {
        return health > 0; 
        }

    void damagedHealth(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }

    void heal(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }

    void chargeSpecialBar() {
        if (specialBar < maxSpecialBar) {
            int gain = (rand() % 2) + 1;
            specialBar += gain;
            if (specialBar > maxSpecialBar) specialBar = maxSpecialBar;
            cout << name << "'s special bar increased by " << gain << "!\n";
        } else {
            cout << name << "'s special bar is already full!\n";
        }
    }

    bool canUseSpecial() const {
        return specialBar >= maxSpecialBar;
    }

    void resetSpecialBar() {
        specialBar = 0;
    }

    int getSpecialBar() const {
        return specialBar;
    }

    virtual int specialMove() = 0;

    float typeAdvantage(power enemyPower) {
        if ((powerr == FIRE && enemyPower == AIR) ||
            (powerr == AIR && enemyPower == EARTH) ||
            (powerr == EARTH && enemyPower == WATER) ||
            (powerr == WATER && enemyPower == FIRE)) {
            return 1.5;
        } else if ((powerr == FIRE && enemyPower == WATER) ||
                   (powerr == AIR && enemyPower == FIRE) ||
                   (powerr == EARTH && enemyPower == AIR) ||
                   (powerr == WATER && enemyPower == EARTH)) {
            return 0.5;
        }
        return 1.0;
    }

    virtual int attack(power opponentPower) {
        float multiplier = typeAdvantage(opponentPower);
        int finalDamage = static_cast<int>(baseDamage * multiplier);
        cout << name << " attacks dealing " << finalDamage << " damage!\n";
        return finalDamage;
    }

    string randomDeathQuote() {
    const string quotes[] = {
        "Skill issue, honestly...!",
        "I'm delulu thinking I could win",
        "I was looking at reels mid-battle!",
        "I'm gonna tweet about this!",
        "At least I died stylishly!",
        "The ick is real rn",
        "I'm in my flop era ig",
        "The way I just got cooked...",
    };
    return quotes[rand() % 8];
}

    void displayHealth() {
        int bar = (health * 20) / 100;
        cout << name << " (" << describeElement(powerr) << ") HP: [";
        for (int i = 0; i < bar; ++i) cout << "#";
        for (int i = bar; i < 20; ++i) cout << "-";
        cout << "] " << health << "/100\n";

        cout << " Special Bar: [";
        for (int i = 0; i < specialBar; ++i) cout << "*";
        for (int i = specialBar; i < maxSpecialBar; ++i) cout << "-";
        cout << "] " << specialBar << "/" << maxSpecialBar << "\n";
    }
};

class PLAYER : public MONSTER {
public:
    PLAYER(string n, power p) : MONSTER(n, p, 100, 20) {}

    int specialMove() override {
        if (!canUseSpecial()) {
            cout << "Special move not ready! Charge it up first.\n";
            return 0;
        }
        resetSpecialBar();
        int dmg = 40;
        cout << name << " uses the SPECIAL MOVE! Massive " << dmg << " damage!\n";
        return dmg;
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

power intToPower(int choice) {
    switch (choice) {
        case 1: return FIRE;
        case 2: return WATER;
        case 3: return AIR;
        case 4: return EARTH;
        default: return FIRE;
    }
}

class Game {
private:
    PLAYER* player1;
    PLAYER* player2;

public:
    Game() {
        srand(time(nullptr));
    }

    ~Game() {
        delete player1;
        delete player2;
    }

    void start() {
        cout<< "\n============================================================================================================================\n"
            << "===================================                      MONSARENA                         =================================\n"
            << "===================================              Fire | Water | Air | Earth                =================================\n"
            << "===================================         Charge your special and defeat your foe!       =================================\n"
            << "============================================================================================================================\n";

        cout << "\nWELCOME TO THE GREAT DUEL\n";
        cout << "\nRead the instructions before going further\n";
        cout << "\n1. You can only use the special move once\n2. It can only be used after the special bar is filled\n3. GOOD LUCK!\n";

        string name1, name2;
        int c1, c2;

        cout << "Player 1, enter your monster's name: ";
        getline(cin, name1);
        do {
            cout << "Choose type for " << name1 << ": 1. Fire  2. Water  3. Air  4. Earth: ";
            cin >> c1;
        } while (c1 < 1 || c1 > 4);
        clearInput();

        cout << "Player 2, enter your monster's name: ";
        getline(cin, name2);
        do {
            cout << "Choose type for " << name2 << ": 1. Fire  2. Water  3. Air  4. Earth: ";
            cin >> c2;
        } while (c2 < 1 || c2 > 4);
        clearInput();

        player1 = new PLAYER(name1, intToPower(c1));
        player2 = new PLAYER(name2, intToPower(c2));

        battleLoop();
    }

    void battleLoop() {
        bool turn = true;

        while (player1->isAlive() && player2->isAlive()) {
            cout << "\n==================================================\n";
            cout << ">>> " << (turn ? player1->getName() : player2->getName()) << "'s Turn <<<\n";
            cout << "==================================================\n";

            player1->displayHealth();
            player2->displayHealth();

            PLAYER* current = turn ? player1 : player2;
            PLAYER* opponent = turn ? player2 : player1;

            int choice;
            cout << "1. Attack  2. Heal (+20 HP)  3. Special Move(USE WISELY)\n";
            cout << "Enter action: ";
            cin >> choice;
            clearInput();

            switch (choice) {
                case 1: {
                    int dmg = current->attack(opponent->getPower());
                    opponent->damagedHealth(dmg);
                    cout << randomCommentary() << "\n";
                    break;
                }
                case 2: {
                    cout << current->getName() << " heals 20 HP!\n";
                    current->heal(20);
                    cout << randomCommentary() << "\n";
                    break;
                }
                case 3: {
                    int dmg = current->specialMove();
                    opponent->damagedHealth(dmg);
                    cout << randomCommentary() << "\n";
                    break;
                }
                default:
                    cout << "Invalid move!!!\n";
            }

            current->chargeSpecialBar();
            turn = !turn;
        }

        endGame();
    }

    void endGame() {
        cout << "\n==== BATTLE RESULT ====\n";
        player1->displayHealth();
        player2->displayHealth();

        
    if (player1->isAlive()) {
        cout << ">> " << player1->getName() << " WINS! <<\n";
        cout << player2->getName() << "'s last words: \"" << player2->randomDeathQuote() << "\"\n";
    } else {
        cout << ">> " << player2->getName() << " WINS! <<\n";
        cout << player1->getName() << "'s last words: \"" << player1->randomDeathQuote() << "\"\n";
    }
}
};

int main() {
    Game g;
    g.start();
    return 0;
}