#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include <cctype>
#include <Windows.h>

#define LENNAME 100
#define LENDATE 15
#define LENINDUSTRY 25
#define NUMBER 1000
#define MAXCONTINENTS 6
#define MAXCOUNTRIES 55
#define MAXSUBJECTS 85


int numberOfContinentsEntered = 0;

struct Сontinent
{
    char *nameOfContinent;
    int numberOfCountries;
    int squareOfContinent;
    struct Country *listOfCountries;
} listOfContinents[MAXCONTINENTS];

struct Country
{
    char *nameOfCountry;
    int numberOfSubject;
    int netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    int incomeOfCountry;
    int expensesOfCountry;
    int budgetDeficitOrSurplusOfCountry;
    struct Subject *listOfSubjects;
};

struct Subject
{
    char *nameOfSubject;
    int numberOfCities;
    int populationOfSubject;
    int squareOfSubject;
    struct City *listOfCities;
};

struct City
{
    char *nameOfCity;
    int populationOfCity;
    int numberOfEnterprises;
    struct Enterprise *listOfEnterprises;
};

struct Enterprise
{
    char *nameOfEnterprise;
    char *citySubjectCountry;
    int turnoverPerYear;
    int netProfitOfEnterprise;
    char *dateOfFoundationEnterprise;
    char *industryOfEnterprise;
};


void initializationContinent(Сontinent* pointerContinent);
void initializationCountry(Country* pointerCountry);
void initializationSubject(Subject* pointerSubject);
void initializationCity(City* pointerCity);
void initializationEnterprise(Enterprise* pointerEnterprise);
void initializationContinent(Сontinent* pointerContinent, int number, int square, char *name, Country countries[], int n);
void initializationCountry(Country* pointerCountry,int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char *name, Subject subjects[], int n);
void initializationSubject(Subject* pointerSubject, int population, int square, int number, char * name, City cities[], int n);
void initializationCity(City* pointerCity, int population, int number, char *name, Enterprise enterprises[], int n);
void initializationEnterprise(Enterprise* pointerEnterprise, int profit, int turnover, char *address, char* date, char* industry, char* name);
void initializationAllStructures(Сontinent* pointerContinent);
void inputAllStructures(Сontinent continent, Country country, Subject subject, City city, Enterprise enterprise);
struct Сontinent inputСontinentFromConsole();
struct Country inputCountryFromConsole();
struct Subject inputSubjectFromConsole();
struct City inputCityFromConsole();
struct Enterprise inputEnterpriseFromConsole();


void deletingNewlineTransitionCharacter(char* line);
int protectionAgainstIncorrectTextInput(char* line);
int checkingForCorrectnessOfDateEntry(char* date);



struct Сontinent theContinent;
struct Country theCountry;
struct Subject theSubject;
struct City theCity;
struct Enterprise theEnterprise;

 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    initializationAllStructures(&listOfContinents[0]);
}



void deletingNewlineTransitionCharacter(char* line) {
    int lineLength;
    lineLength = strlen(line);
    line[lineLength - 1] = '\0';
}

int protectionAgainstIncorrectTextInput(char* line) {
    int i, lineLength;
    if (line[0] == '\n') {
        puts("Ошибка! Данное поле не может быть пустым!");
        return 1;
    }
    lineLength = strlen(line);
    if (line[lineLength - 1] != '\n') {
        puts("Ошибка! Количество символов превышает допустимое зачение!");
        return 2;
    }
    for (i = 0; i < lineLength; i++)
        if ((!ispunct(line[i])) && (!isspace(line[i])))
            return 0;
    puts("Ошибка! В данном поле должны присутвовать буквы или цифры!");
    return 3;
}

int checkingForCorrectnessOfDateEntry(char* date) {
    int i, flag;
    flag = 0;
    if ((!isdigit(date[0])) || (!isdigit(date[1]))) {
        puts("Число введено некорректно!");
        flag = 1;
    }
    if ((date[2] != '.') || (date[5]) != '.') {
        puts("После числа и месяца необходимо поставить точку !!!");
        flag = 2;
    }
    if ((!isdigit(date[4])) || (!isdigit(date[5]))) {
        puts("Месяц введен некорректно!");
        flag = 3;
    }
    for (i = 6; i < 10; i++) 
        if (!isdigit(date[i])) {
            puts("Год введен некорректно!");
            flag = 4;
            break;
        }
    if (flag)
        puts("ШАБЛОН ВВОДА ДАТЫ - дд.мм.гггг");
    date[10] = '\0';
    return flag;
}

// Инициализация структур без параметров

void initializationContinent(Сontinent* pointerContinent) {
    pointerContinent->numberOfCountries = 0;
    pointerContinent->squareOfContinent = 0;
    pointerContinent->nameOfContinent = NULL;
    pointerContinent->listOfCountries = (struct Country*)malloc(sizeof(struct Country));
}

void initializationCountry(Country* pointerCountry) {
    pointerCountry->budgetDeficitOrSurplusOfCountry = 0;
    pointerCountry->expensesOfCountry = 0;
    pointerCountry->incomeOfCountry = 0;
    pointerCountry->netProfitCountryEnterprises = 0;
    pointerCountry->numberOfSubject = 0;
    pointerCountry->populationOfCountry = 0;
    pointerCountry->squareOfCountry = 0;
    pointerCountry->nameOfCountry = NULL;
    pointerCountry->listOfSubjects = (struct Subject*)malloc(sizeof(struct Subject));
}

void initializationSubject(Subject* pointerSubject) {
    pointerSubject->populationOfSubject = 0;
    pointerSubject->squareOfSubject = 0;
    pointerSubject->numberOfCities = 0;
    pointerSubject->nameOfSubject = NULL;
    pointerSubject->listOfCities = (struct City*)malloc(sizeof(struct City));
}

void initializationCity(City* pointerCity) {
    pointerCity->populationOfCity = 0;
    pointerCity->numberOfEnterprises = 0;
    pointerCity->nameOfCity = NULL;
    pointerCity->listOfEnterprises = (struct Enterprise*)malloc(sizeof(struct Enterprise));
}

void initializationEnterprise(Enterprise* pointerEnterprise) {
    pointerEnterprise->netProfitOfEnterprise = 0;
    pointerEnterprise->turnoverPerYear = 0;
    pointerEnterprise->citySubjectCountry = NULL;
    pointerEnterprise->dateOfFoundationEnterprise = NULL;
    pointerEnterprise->industryOfEnterprise = NULL;
    pointerEnterprise->nameOfEnterprise = NULL;
}


// Инициализация структур с параметрами

void initializationContinent(Сontinent* pointerContinent, int number, int square, char *name, Country countries[]) {
    int i;
    int lenOfName = strlen(name);
    pointerContinent->nameOfContinent = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerContinent->nameOfContinent, name);
    pointerContinent->numberOfCountries = number;
    pointerContinent->squareOfContinent = square;
    pointerContinent->listOfCountries = (struct Country*)malloc(number * sizeof(struct Country));
    for (i = 0; i < number; i++)
        *(pointerContinent->listOfCountries + i) = countries[i];

}

void initializationCountry(Country* pointerCountry, int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char* name, Subject subjects[]) {
    int i;
    int lenOfName = strlen(name);
    pointerCountry->nameOfCountry = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerCountry->nameOfCountry, name);
    pointerCountry->budgetDeficitOrSurplusOfCountry = budget;
    pointerCountry->expensesOfCountry = expenses;
    pointerCountry->incomeOfCountry = income;
    pointerCountry->netProfitCountryEnterprises = profitEnterprises;
    pointerCountry->numberOfSubject = number;
    pointerCountry->populationOfCountry = population;
    pointerCountry->squareOfCountry = square;
    pointerCountry->listOfSubjects = (struct Subject*)malloc(number * sizeof(struct Subject));
    for (i = 0; i < number; i++)
        *(pointerCountry->listOfSubjects + i) = subjects[i];
}

void initializationSubject(Subject* pointerSubject, int population, int square, int number, char* name, City cities[]) {
    int i;
    int lenOfName = strlen(name);
    pointerSubject->nameOfSubject = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerSubject->nameOfSubject, name);
    pointerSubject->populationOfSubject = population;
    pointerSubject->squareOfSubject = square;
    pointerSubject->numberOfCities = number;
    pointerSubject->listOfCities = (struct City*)malloc(number * sizeof(struct City));
    for (i = 0; i < number; i++)
        *(pointerSubject->listOfCities + i) = cities[i];
}

void initializationCity(City* pointerCity, int population, int number, char* name, Enterprise enterprises[]) {
    int i;
    int lenOfName = strlen(name);
    pointerCity->nameOfCity = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerCity->nameOfCity, name);
    pointerCity->populationOfCity = population;
    pointerCity->numberOfEnterprises = number;
    pointerCity->listOfEnterprises = (struct Enterprise*)malloc(number * sizeof(struct Enterprise));
    for (i = 0; i < number; i++)
        *(pointerCity->listOfEnterprises + i) = enterprises[i];
}

void initializationEnterprise(Enterprise* pointerEnterprise, int profit, int turnover, char* address, char* date, char* industry, char* name) {
    int length;
    length = strlen(name);
    pointerEnterprise->nameOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(pointerEnterprise->nameOfEnterprise, name);
    length = strlen(industry);
    pointerEnterprise->industryOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(pointerEnterprise->industryOfEnterprise, industry);
    length = strlen(date);
    pointerEnterprise->dateOfFoundationEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(pointerEnterprise->dateOfFoundationEnterprise, date);
    length = strlen(address);
    strcpy(pointerEnterprise->citySubjectCountry, address);
    pointerEnterprise->citySubjectCountry = (char*)calloc(length, sizeof(char));
    pointerEnterprise->netProfitOfEnterprise = profit;
    pointerEnterprise->turnoverPerYear = turnover;
}

// Инициализация всех структур без параметров
void initializationAllStructures(Сontinent* pointerContinent) {

    initializationContinent(pointerContinent);
    initializationCountry(pointerContinent->listOfCountries);
    initializationSubject(pointerContinent->listOfCountries->listOfSubjects);
    initializationCity(pointerContinent->listOfCountries->listOfSubjects->listOfCities);
    initializationEnterprise(pointerContinent->listOfCountries->listOfSubjects->listOfCities->listOfEnterprises);
}

// Ввод из консоли
struct Сontinent inputСontinentFromConsole() {
    char name[LENNAME];
    int number;
    char countries[55][LENNAME];
    int square;
    int i, length;
    do {
        puts("Введите название континента:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    puts("Введите количество стран на континенте:");
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите количество стран на континенте:\n");
    }
    puts("Введите площадь континента (в кв. км):");
    while (scanf("%d", &square) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите площадь континента (в кв. км):\n");
    }
    length = strlen(name);
    theContinent.nameOfContinent = (char*)calloc(length, sizeof(char));
    strcpy(theContinent.nameOfContinent, name);
    theContinent.numberOfCountries = number;
    theContinent.squareOfContinent = square;
    return theContinent;
}


struct Country inputCountryFromConsole() {
    char name[LENNAME];
    int number;
    char subjects[85][LENNAME];
    int square;
    int income;
    int profit;
    int expenses;
    int budget;
    int population;
    int i, length;
    do {
        puts("Введите название страны:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    puts("Введите население страны:");
    while (scanf("%d", &population) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите население страны:\n");
    }
    puts("Введите количество субъектов в стране:");
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите количество субъектов в стране:\n");
    }
    puts("Введите площадь страны:");
    while (scanf("%d", &square) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите площадь страны:\n");
    }
    puts("Введите прибыль всех предприятий страны:");
    while (scanf("%d", &profit) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите прибыль всех предприятий страны:\n");
    }
    puts("Введите доход страны:");
    while (scanf("%d", &income) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите доход страны:\n");
    }
    puts("Введите расходы страны:");
    while (scanf("%d", &expenses) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите расходы страны:\n");
    }
    puts("Введите дефицит/профицит бюджета страны:");
    while (scanf("%d", &budget) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите дефицит/профицит бюджета страны:\n");
    }
    length = strlen(name);
    theCountry.nameOfCountry = (char*)calloc(length, sizeof(char));
    strcpy(theCountry.nameOfCountry, name);
    theCountry.populationOfCountry = population;
    theCountry.numberOfSubject = number;
    theCountry.squareOfCountry = square;
    theCountry.incomeOfCountry = income;
    theCountry.expensesOfCountry = expenses;
    theCountry.netProfitCountryEnterprises = profit;
    theCountry.budgetDeficitOrSurplusOfCountry = budget;
    return theCountry;
}

struct Subject inputSubjectFromConsole() {
    char name[LENNAME];
    int number;
    char cities[1000][LENNAME];
    int square;
    int population;
    int i, length;
    do {
        puts("Введите название субъекта:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    puts("Введите население субъекта:");
    while (scanf("%d", &population) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите население субъекта:\n");
    }
    puts("Введите количество городов в субъекте:");
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите количество городов в субъекте:\n");
    }
    puts("Введите площадь субъекта:");
    while (scanf("%d", &square) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите площадь субъекта:\n");
    }
    while (getchar() != '\n');
    length = strlen(name);
    theSubject.nameOfSubject = (char*)calloc(length, sizeof(char));
    strcpy(theSubject.nameOfSubject, name);
    theSubject.numberOfCities = number;
    theSubject.squareOfSubject = square;
    theSubject.populationOfSubject = population;
    return theSubject;
}


struct City inputCityFromConsole() {
    char name[LENNAME];
    int number;
    char enterprises[1000][LENNAME];
    int population;
    int i, length;
    do {
        puts("Введите название города:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    puts("Введите население города:");
    while (scanf("%d", &population) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите население города:\n");
    }
    puts("Введите количество предприятий в городе:");
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите количество предприятий в городе:\n");
    }
    length = strlen(name);
    theCity.nameOfCity = (char*)calloc(length, sizeof(char));
    strcpy(theCity.nameOfCity, name);
    theCity.numberOfEnterprises = number;
    theCity.populationOfCity = population;
    return theCity;
}

struct Enterprise inputEnterpriseFromConsole() {
    char name[LENNAME];
    char address[LENNAME * 3];
    int turnover;
    int profit;
    char date[15];
    char industry[LENNAME];
    int i, length;
    do {
        puts("Введите название предприятия:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    do {
        puts("Введите город, субъект и город в котором находится предприятие:");
        fgets(address, LENNAME * 3, stdin);
    } while (protectionAgainstIncorrectTextInput(address));
    deletingNewlineTransitionCharacter(address);
    do {
        do {
            puts("Введите дату основания предприятия:");
            fgets(date, 15, stdin);
        } while (protectionAgainstIncorrectTextInput(date));
    } while (checkingForCorrectnessOfDateEntry(date));
    deletingNewlineTransitionCharacter(date);
    do {
        puts("Введите отрасль предприятия:");
        fgets(industry, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(industry));
    deletingNewlineTransitionCharacter(industry);
    puts("Введите оборот за год:");
    while (scanf("%d", &turnover) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите оборот за год:\n");
    }
    puts("Введите прибыль предприятия:");
    while (scanf("%d", &profit) != 1) {
        while (getchar() != '\n');
        printf("\nОшибка ввода!\nВведите прибыль предприятия:\n");
    }
    length = strlen(name);
    theEnterprise.nameOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(theEnterprise.nameOfEnterprise, name);
    length = strlen(address);
    theEnterprise.citySubjectCountry = (char*)calloc(length, sizeof(char));
    strcpy(theEnterprise.citySubjectCountry, address);
    length = strlen(date);
    theEnterprise.dateOfFoundationEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(theEnterprise.dateOfFoundationEnterprise, date);
    length = strlen(industry);
    theEnterprise.industryOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(theEnterprise.industryOfEnterprise, industry);
    return theEnterprise;
}

void inputAllStructures(Сontinent continent, Country country, Subject subject, City city, Enterprise enterprise) {
    int numberOfCountriesEntered = 0;
    int numberOfSubjectsEntered = 0;
    if (numberOfContinentsEntered != MAXCONTINENTS)
        do {
            continent = inputСontinentFromConsole();
            numberOfContinentsEntered++;
            if (numberOfContinentsEntered == MAXCONTINENTS)
                puts("Вы ввели все существующие континеты!");
            else {
                puts("Для завершения ввода континетов нажмите Esc.");
                puts("Для продолжения любую другую клавишу.\n");
            }
        } while ((_getch() != 27) && (numberOfContinentsEntered != MAXCONTINENTS));
    do {
        country = inputCountryFromConsole();
        numberOfCountriesEntered++;
        if (numberOfCountriesEntered == MAXCOUNTRIES)
            puts("Вы ввели максимальное количество стан для одного континета!");
        else {
            puts("Для завершения ввода стран нажмите Esc.");
            puts("Для продолжения любую другую клавишу.\n");
        }
    } while ((_getch() != 27) && (numberOfCountriesEntered != MAXCOUNTRIES));
    do {
        subject = inputSubjectFromConsole();
        numberOfSubjectsEntered++;
        if (numberOfSubjectsEntered == MAXSUBJECTS)
            puts("Вы ввели максимальное количество субъектов для одной страны!");
        else {
            puts("Для завершения ввода субъектов нажмите Esc.");
            puts("Для продолжения любую другую клавишу.\n");
        }
    } while ((_getch() != 27) && (numberOfSubjectsEntered != MAXSUBJECTS));
    do {
        city = inputCityFromConsole();
    } while (_getch() != 27);
    do {
        enterprise = inputEnterpriseFromConsole();
    } while (_getch() != 27);
}