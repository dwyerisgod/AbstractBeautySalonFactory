#include <iostream>
using namespace std;

// Абстрактні класи для послуг
class Haircut {
public:
    virtual ~Haircut() {}
    virtual void cutHair() = 0;
};

class Manicure {
public:
    virtual ~Manicure() {}
    virtual void doManicure() = 0;
};

class Pedicure {
public:
    virtual ~Pedicure() {}
    virtual void doPedicure() = 0;
};

// Конкретні класи для послуги салону "Luxury Beauty"
class LuxuryHaircut : public Haircut {
public:
    void cutHair() override {
        cout << "Робимо розкішну стрижку" << endl;
    }
};

class LuxuryManicure : public Manicure {
public:
    void doManicure() override {
        cout << "Робимо розкішний манікюр" << endl;
    }
};

class LuxuryPedicure : public Pedicure {
public:
    void doPedicure() override {
        cout << "Робимо розкішний педикюр" << endl;
    }
};

// Абстрактна фабрика
class BeautySalonFactory {
public:
    virtual ~BeautySalonFactory() {}
    virtual Haircut* createHaircutService() = 0;
    virtual Manicure* createManicureService() = 0;
    virtual Pedicure* createPedicureService() = 0;
};

// Конкретна фабрика для салону краси "Luxury Beauty"
class LuxuryBeautyFactory : public BeautySalonFactory {
public:
    Haircut* createHaircutService() override {
        return new LuxuryHaircut();
    }

    Manicure* createManicureService() override {
        return new LuxuryManicure();
    }

    Pedicure* createPedicureService() override {
        return new LuxuryPedicure();
    }
};

// Конкретні класи для послуги салону "Economy Beauty"
class EconomyHaircut : public Haircut {
public:
    void cutHair() override {
        cout << "Робимо економ стрижку" << endl;
    }
};

class EconomyManicure : public Manicure {
public:
    void doManicure() override {
        cout << "Робимо економ манікюр" << endl;
    }
};

class EconomyPedicure : public Pedicure {
public:
    void doPedicure() override {
        cout << "Робимо економ педикюр" << endl;
    }
};

// Абстрактний клас фабрики для салону краси "Economy Beauty"
class EconomyBeautyFactory : public BeautySalonFactory {
public:
    Haircut* createHaircutService() override {
        return new EconomyHaircut();
    }

    Manicure* createManicureService() override {
        return new EconomyManicure();
    }

    Pedicure* createPedicureService() override {
        return new EconomyPedicure();
    }
};

// Конкретні класи для послуги салону "Premium Beauty"
class PremiumHaircut : public Haircut {
public:
    void cutHair() override {
        cout << "Робимо преміум стрижку" << endl;
    }
};

class PremiumManicure : public Manicure {
public:
    void doManicure() override {
        cout << "Робимо преміум манікюр" << endl;
    }
};

class PremiumPedicure : public Pedicure {
public:
    void doPedicure() override {
        cout << "Робимо преміум педикюр" << endl;
    }
};

// Конкретні класи для послуги салону "Premium Beauty"
class PremiumBeautyFactory : public BeautySalonFactory {
public:
    Haircut* createHaircutService() override {
        return new PremiumHaircut();
    }

    Manicure* createManicureService() override {
        return new PremiumManicure();
    }

    Pedicure* createPedicureService() override {
        return new PremiumPedicure();
    }
};

int main() {
    string salonType = "luxury"; // або "economy" або "premium"
    BeautySalonFactory* salonFactory = nullptr;

    if (salonType == "luxury") {
        salonFactory = new LuxuryBeautyFactory();
    } else if (salonType == "economy") {
        salonFactory = new EconomyBeautyFactory();
    } else if (salonType == "premium") {
        salonFactory = new PremiumBeautyFactory();
    } else {
        cout << "Неверный тип салона красоты." << endl;
        return 1;
    }

    Haircut* haircutService = salonFactory->createHaircutService();
    Manicure* manicureService = salonFactory->createManicureService();
    Pedicure* pedicureService = salonFactory->createPedicureService();

    haircutService->cutHair();
    manicureService->doManicure();
    pedicureService->doPedicure();

    delete haircutService;
    delete manicureService;
    delete pedicureService;
    delete salonFactory;

    int a = 0;

    cout << "Enter value of a -" << endl;
    cin >> a;

    return 0;
}
