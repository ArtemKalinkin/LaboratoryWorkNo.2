#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

#define LENNAME 100
#define LENDATE 15
#define LENINDUSTRY 25
#define NUMBER 1000

struct Сontinent
{
    char *nameOfContinent;
    int numberOfCountries;
    char **listOfCountries;
    int squareOfContinent;
};

struct Country
{
    char *nameOfCountry;
    int numberOfSubject;
    char **listOfSubject;
    int netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    int incomeOfCountry;
    int expensesOfCountry;
    int budgetDeficitOrSurplusOfCountry;
};

struct Subject
{
    char *nameOfSubject;
    char **listOfCities;
    int numberOfCities;
    int populationOfSubject;
    int squareOfSubject;
};

struct City
{
    char *nameOfCity;
    char **listOfEnterprises;
    int populationOfCity;
    int numberOfEnterprises;
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
void initializationContinent(Сontinent* pointerContinent, int number, int square, char *name, char *countries[]);
void initializationCountry(Country* pointerCountry,int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char *name, char *subjects[]);
void initializationSubject(Subject* pointerSubject, int population, int square, int number, char * name, char *cities[]);
void initializationCity(City* pointerCity, int population, int number, char *name, char *enterprises[]);
void initializationEnterprise(Enterprise* pointerEnterprise, int profit, int turnover, char * address, char *date, char *industry, char *name);
struct Сontinent inputСontinentFromConsole();
struct Country inputCountryFromConsole();
struct Subject inputSubjectFromConsole();
struct City inputCityFromConsole();
struct Enterprise inputEnterpriseFromConsole();


void deletingNewlineTransitionCharacter(char* line) {
    int lineLength;
    lineLength = strlen(line);
    line[lineLength - 1] = '\0';
}



struct Сontinent theContinent;
struct Country theCountry;
struct Subject theSubject;
struct City theCity;
struct Enterprise theEnterprise;

struct Сontinent continents[6];
struct Country countries[55];
struct Subject subjects[85];
struct City cities[1000];
struct Enterprise enterprises[1000];




int main()
{
    
}

// Инициализация структур без параметров

void initializationContinent(Сontinent* pointerContinent) {
    (*pointerContinent).numberOfCountries = 0;
    (*pointerContinent).squareOfContinent = 0;
    (*pointerContinent).nameOfContinent = NULL;
    (*pointerContinent).listOfCountries = NULL;
}

void initializationCountry(Country* pointerCountry) {
    (*pointerCountry).budgetDeficitOrSurplusOfCountry = 0;
    (*pointerCountry).expensesOfCountry = 0;
    (*pointerCountry).incomeOfCountry = 0;
    (*pointerCountry).netProfitCountryEnterprises = 0;
    (*pointerCountry).numberOfSubject = 0;
    (*pointerCountry).populationOfCountry = 0;
    (*pointerCountry).squareOfCountry = 0;
    (*pointerCountry).listOfSubject = NULL;
    (*pointerCountry).nameOfCountry = NULL;
}

void initializationSubject(Subject* pointerSubject) {
    (*pointerSubject).populationOfSubject = 0;
    (*pointerSubject).squareOfSubject = 0;
    (*pointerSubject).numberOfCities = 0;
    (*pointerSubject).nameOfSubject = NULL;
    (*pointerSubject).listOfCities = NULL;
}

void initializationCity(City* pointerCity) {
    (*pointerCity).populationOfCity = 0;
    (*pointerCity).numberOfEnterprises = 0;
    (*pointerCity).nameOfCity = NULL;
    (*pointerCity).listOfEnterprises = NULL;
}

void initializationEnterprise(Enterprise* pointerEnterprise) {
    (*pointerEnterprise).netProfitOfEnterprise = 0;
    (*pointerEnterprise).turnoverPerYear = 0;
    (*pointerEnterprise).citySubjectCountry = NULL;
    (*pointerEnterprise).dateOfFoundationEnterprise = NULL;
    (*pointerEnterprise).industryOfEnterprise = NULL;
    (*pointerEnterprise).nameOfEnterprise = NULL;
}


// Инициализация структур с параметрами

void initializationContinent(Сontinent* pointerContinent, int number, int square, char *name, char *countries[]) {
    int lenOfName = strlen(name);
    (*pointerContinent).nameOfContinent = (char*)calloc(lenOfName, sizeof(char));
    (*pointerContinent).numberOfCountries = number;
    (*pointerContinent).squareOfContinent = square;
    strcpy((*pointerContinent).nameOfContinent, name);
    (*pointerContinent).listOfCountries = (char**)calloc((*pointerContinent).numberOfCountries, sizeof(char*));
    for (int i = 0; i < (*pointerContinent).numberOfCountries; i++) 
        (*pointerContinent).listOfCountries[i] = (char*)calloc(LENNAME, sizeof(char));
    for (int i = 0; countries[i]; i++)
        strcpy((*pointerContinent).listOfCountries[i], countries[i]);
}

void initializationCountry(Country* pointerCountry, int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char* name, char *subjects[]) {
    (*pointerCountry).budgetDeficitOrSurplusOfCountry = budget;
    (*pointerCountry).expensesOfCountry = expenses;
    (*pointerCountry).incomeOfCountry = income;
    (*pointerCountry).netProfitCountryEnterprises = profitEnterprises;
    (*pointerCountry).numberOfSubject = number;
    (*pointerCountry).populationOfCountry = population;
    (*pointerCountry).squareOfCountry = square;
    strcpy((*pointerCountry).nameOfCountry, name);
    (*pointerCountry).listOfSubject = (char**)calloc((*pointerCountry).numberOfSubject, sizeof(char));
    for (int i = 0; i < (*pointerCountry).numberOfSubject; i++)
        (*pointerCountry).listOfSubject[i] = (char*)calloc(LENNAME, sizeof(char));
    for (int i = 0; subjects[i]; i++)
        strcpy((*pointerCountry).listOfSubject[i],subjects[i]);
}

void initializationSubject(Subject* pointerSubject, int population, int square, int number, char* name, char *cities[]) {
    (*pointerSubject).populationOfSubject = population;
    (*pointerSubject).squareOfSubject = square;
    (*pointerSubject).numberOfCities = number;
    strcpy((*pointerSubject).nameOfSubject, name);
    (*pointerSubject).listOfCities = (char**)calloc((*pointerSubject).numberOfCities, sizeof(char));
    for (int i = 0; i < (*pointerSubject).numberOfCities; i++)
        (*pointerSubject).listOfCities[i] = (char*)calloc(LENNAME, sizeof(char));
    for (int i = 0; cities[i]; i++)
        strcpy((*pointerSubject).listOfCities[i], cities[i]); 
}

void initializationCity(City* pointerCity, int population, int number, char* name, char *enterprises[]) {
    (*pointerCity).populationOfCity = population;
    (*pointerCity).numberOfEnterprises = number;
    strcpy((*pointerCity).nameOfCity, name);
    (*pointerCity).listOfEnterprises = (char**)calloc((*pointerCity).numberOfEnterprises, sizeof(char));
    for (int i = 0; i < (*pointerCity).numberOfEnterprises; i++)
        (*pointerCity).listOfEnterprises[i] = (char*)calloc(LENNAME, sizeof(char));
    for (int i = 0; enterprises[i]; i++)
        strcpy((*pointerCity).listOfEnterprises[i], enterprises[i]);
}

void initializationEnterprise(Enterprise* pointerEnterprise, int profit, int turnover, char* address, char* date, char* industry, char* name) {
    (*pointerEnterprise).netProfitOfEnterprise = profit;
    (*pointerEnterprise).turnoverPerYear = turnover;
    strcpy((*pointerEnterprise).citySubjectCountry, address);
    strcpy((*pointerEnterprise).dateOfFoundationEnterprise, date);
    strcpy((*pointerEnterprise).industryOfEnterprise, industry);
    strcpy((*pointerEnterprise).nameOfEnterprise, name);
}

// Ввод из консоли
struct Сontinent inputСontinentFromConsole() {
    char name[LENNAME];
    int number;
    char countries[55][LENNAME];
    int square;
    int i, length;
    puts("Введите название континента:");
    fgets(name, LENNAME, stdin);
    deletingNewlineTransitionCharacter(name);
    puts("Введите количество стран на континенте:");
    scanf("%d", &number);
    puts("Введите площадь континента");
    scanf("%d", &square);
    puts("Введите список стран\n");
    theContinent.listOfCountries = (char**)calloc(number, sizeof(char*));
    for (i = 0; i < number; i++)
        theContinent.listOfCountries[i] = (char*)calloc(LENNAME, sizeof(char));
    i = 0;
    do {
        puts("Введите название города:");
        fgets(countries[i], LENNAME, stdin);
        deletingNewlineTransitionCharacter(countries[i]);
        puts("Для завершения ввода списка нажмите Esc.");
        puts("Для продолжения любую другую клавишу.");
        strcpy(theContinent.listOfCountries[i], countries[i]);
        i++;
    } while (_getch() != 27);
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
    puts("Введите название страны:");
    fgets(name, LENNAME, stdin);
    deletingNewlineTransitionCharacter(name);
    puts("Введите население страны:");
    scanf("%d", &population);
    puts("Введите количество субъектов в стране:");
    scanf("%d", &number);
    puts("Введите площадь страны");
    scanf("%d", &square);
    puts("Введите прибыль всех предприятий страны:");
    scanf("%d", &profit);
    puts("Введите доход страны:");
    scanf("%d", &income);
    puts("Введите расходы страны:");
    scanf("%d", &expenses);
    puts("Введите дефицит/профицит бюджета страны:");
    scanf("%d", &budget);
    puts("Введите список субъектов\n");
    theCountry.listOfSubject = (char**)calloc(theCountry.numberOfSubject, sizeof(char));
    for (i = 0; i < number; i++)
        theCountry.listOfSubject[i] = (char*)calloc(LENNAME, sizeof(char));
    i = 0;
    do {
        puts("Введите название субъекта:");
        fgets(subjects[i], LENNAME, stdin);
        deletingNewlineTransitionCharacter(subjects[i]);
        puts("Для завершения ввода списка нажмите Esc.");
        puts("Для продолжения любую другую клавишу.");
        strcpy(theCountry.listOfSubject[i], subjects[i]);
        i++;
    } while (_getch() != 27);
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
    puts("Введите название субъекта:");
    fgets(name, LENNAME, stdin);
    deletingNewlineTransitionCharacter(name);
    puts("Введите население субъекта:");
    scanf("%d", &population);
    puts("Введите количество городов в субъекте:");
    scanf("%d", &number);
    puts("Введите площадь субъекта");
    scanf("%d", &square);
    puts("Введите список городов\n");
    theSubject.listOfCities = (char**)calloc(number, sizeof(char*));
    for (i = 0; i < number; i++)
        theSubject.listOfCities[i] = (char*)calloc(LENNAME, sizeof(char));
    i = 0;
    do {
        puts("Введите название города:");
        fgets(cities[i], LENNAME, stdin);
        deletingNewlineTransitionCharacter(cities[i]);
        puts("Для завершения ввода списка нажмите Esc.");
        puts("Для продолжения любую другую клавишу.");
        strcpy(theSubject.listOfCities[i], cities[i]);
        i++;
    } while (_getch() != 27);
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
    puts("Введите название города:");
    fgets(name, LENNAME, stdin);
    deletingNewlineTransitionCharacter(name);
    puts("Введите население города:");
    scanf("%d", &population);
    puts("Введите количество предприятий в городе:");
    scanf("%d", &number);
    puts("Введите список предприятий\n");
    theCity.listOfEnterprises = (char**)calloc(number, sizeof(char*));
    for (i = 0; i < number; i++)
        theCity.listOfEnterprises[i] = (char*)calloc(LENNAME, sizeof(char));
    i = 0;
    do {
        puts("Введите название предприятия:");
        fgets(enterprises[i], LENNAME, stdin);
        deletingNewlineTransitionCharacter(enterprises[i]);
        puts("Для завершения ввода списка нажмите Esc.");
        puts("Для продолжения любую другую клавишу.");
        strcpy(theCity.listOfEnterprises[i], enterprises[i]);
        i++;
    } while (_getch() != 27);
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
    puts("Введите название предприятия:");
    fgets(name, LENNAME, stdin);
    deletingNewlineTransitionCharacter(name);
    puts("Введите город, субъект и город в котором находится предприятие:");
    fgets(address, LENNAME * 3, stdin);
    deletingNewlineTransitionCharacter(address);
    puts("Введите дату основания предприятия:");
    fgets(date, 15, stdin);
    deletingNewlineTransitionCharacter(date);
    puts("Введите отрасль предприятия:");
    fgets(industry, LENNAME, stdin);
    deletingNewlineTransitionCharacter(industry);
    puts("Введите оборот за год");
    scanf("%d", &turnover);
    puts("Введите прибыль предприятия");
    scanf("%d", &profit);
    length = strlen(name);
    theEnterprise.nameOfEnterprise = (char*)calloc(length, sizeof(char));
    length = strlen(address);
    theEnterprise.citySubjectCountry = (char*)calloc(length, sizeof(char));
    length = strlen(date);
    theEnterprise.dateOfFoundationEnterprise = (char*)calloc(length, sizeof(char));
    length = strlen(industry);
    theEnterprise.industryOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(theEnterprise.nameOfEnterprise, name);
    strcpy(theEnterprise.industryOfEnterprise, industry);
    strcpy(theEnterprise.citySubjectCountry, address);
    strcpy(theEnterprise.dateOfFoundationEnterprise, date);
}

