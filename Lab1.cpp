#include <iostream>
using namespace std;

// Абстрактный класс для стрижки
class Haircut {
public:
    virtual void cutHair() = 0;
};

// Абстрактный класс для маникюра
class Manicure {
public:
    virtual void doManicure() = 0;
};

// Абстрактный класс для педикюра
class Pedicure {
public:
    virtual void doPedicure() = 0;
};

// Абстрактная фабрика для салона красоты
class BeautySalonFactory {
public:
    virtual Haircut* createHaircutService() = 0;
    virtual Manicure* createManicureService() = 0;
    virtual Pedicure* createPedicureService() = 0;
};

// Конкретная фабрика для салона красоты "Luxury Beauty"
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

// Конкретная фабрика для салона красоты "Economy Beauty"
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

// Конкретная фабрика для салона красоты "Premium Beauty"
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

// Конкретные классы для услуг салона "Luxury Beauty"
class LuxuryHaircut : public Haircut {
public:
    void cutHair() override {
        cout << "Делаем роскошную стрижку" << endl;
    }
};

class LuxuryManicure : public Manicure {
public:
    void doManicure() override {
        std::cout << "Делаем роскошный маникюр" << std::endl;
    }
};

class LuxuryPedicure : public Pedicure {
public:
    void doPedicure() override {
        std::cout << "Делаем роскошный педикюр" << std::endl;
    }
};

// Конкретные классы для услуг салона "Economy Beauty"
class EconomyHaircut : public Haircut {
public:
    void cutHair() override {
        std::cout << "Делаем экономичную стрижку" << std::endl;
    }
};

class EconomyManicure : public Manicure {
public:
    void doManicure() override {
        std::cout << "Делаем экономичный маникюр" << std::endl;
    }
};

class EconomyPedicure : public Pedicure {
public:
    void doPedicure() override {
        std::cout << "Делаем экономичный педикюр" << std::endl;
    }
};

// Конкретные классы для услуг салона "Premium Beauty"
class PremiumHaircut : public Haircut {
public:
    void cutHair() override {
        std::cout << "Делаем премиум стрижку" << std::endl;
    }
};

class PremiumManicure : public Manicure {
public:
    void doManicure() override {
        std::cout << "Делаем премиум маникюр" << std::endl;
    }
};

class PremiumPedicure : public Pedicure {
public:
    void doPedicure() override {
        std::cout << "Делаем премиум педикюр" << std::endl;
    }
};

int main() {
    std::string salonType = "luxury"; // или "economy" или "premium"
    BeautySalonFactory* salonFactory = nullptr;

    if (salonType == "luxury") {
        salonFactory = new LuxuryBeautyFactory();
    } else if (salonType == "economy") {
        salonFactory = new EconomyBeautyFactory();
    } else if (salonType == "premium") {
        salonFactory = new PremiumBeautyFactory();
    } else {
        std::cerr << "Неверный тип салона красоты." << std::endl;
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

    return 0;
}
