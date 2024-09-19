#include <iostream>
#include <string>
using namespace std;

class Instrument {
protected:
    string name;
    int yearOfInvention;

public:
    Instrument(const string& name, int yearOfInvention)
        : name(name), yearOfInvention(yearOfInvention) {}

    virtual void playSound() const = 0;
    virtual void adjustVolume() const = 0;
    virtual ~Instrument() {}
};
class StringInstrument : public Instrument {
private:
    int numberOfStrings;

public:
    StringInstrument(const string& name, int yearOfInvention, int numberOfStrings)
        : Instrument(name, yearOfInvention), numberOfStrings(numberOfStrings) {}

    void playSound() const override {
        cout << name << " (invented in " << yearOfInvention << ") plays string sounds on "
            << numberOfStrings << " strings." << endl;
    }

    void adjustVolume() const override {
        cout << "Adjusting the volume of the string instrument: " << name << endl;
    }
};
class WindInstrument : public Instrument {
private:
    string typeOfMouthpiece;

public:
    WindInstrument(const string& name, int yearOfInvention, const string& typeOfMouthpiece)
        : Instrument(name, yearOfInvention), typeOfMouthpiece(typeOfMouthpiece) {}

    void playSound() const override {
        cout << name << " (invented in " << yearOfInvention << ") plays wind sounds through "
            << typeOfMouthpiece << "." << endl;
    }

    void adjustVolume() const override {
        cout << "Adjusting the volume of the wind instrument: " << name << endl;
    }
};
class PercussionInstrument : public Instrument {
private:
    string typeOfPercussion;

public:
    PercussionInstrument(const string& name, int yearOfInvention, const string& typeOfPercussion)
        : Instrument(name, yearOfInvention), typeOfPercussion(typeOfPercussion) {}

    void playSound() const override {
        cout << name << " (invented in " << yearOfInvention << ") plays percussion sounds through "
            << typeOfPercussion << "." << endl;
    }

    void adjustVolume() const override {
        cout << "Adjusting the volume of the percussion instrument: " << name << endl;
    }
};

int main() {
    StringInstrument violin("Violin", 1550, 4);
    WindInstrument flute("Flute", 1700, "narrow tube");
    PercussionInstrument drum("Drum", 5000, "leather drum");
    Instrument* instruments[] = { &violin, &flute, &drum };
    for (int i = 0; i < 3; ++i) {
        instruments[i]->playSound();
        instruments[i]->adjustVolume();
        cout << endl;
    }
}