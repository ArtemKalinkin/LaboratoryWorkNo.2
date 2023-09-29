#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>

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
    char *citySubjectCoutry;
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
struct Сontinent inputCountryFromConsole();
struct Сontinent inputSubjectFromConsole();
struct Сontinent inputCityFromConsole();
struct Сontinent inputEnterpriseFromConsole();








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
    (*pointerEnterprise).citySubjectCoutry = NULL;
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
    strcpy((*pointerEnterprise).citySubjectCoutry, address);
    strcpy((*pointerEnterprise).dateOfFoundationEnterprise, date);
    strcpy((*pointerEnterprise).industryOfEnterprise, industry);
    strcpy((*pointerEnterprise).nameOfEnterprise, name);
}

// Ввод из консоли

struct Сontinent inputСontinentFromConsole();
struct Сontinent inputCountryFromConsole();
struct Сontinent inputSubjectFromConsole();
struct Сontinent inputCityFromConsole();
struct Сontinent inputEnterpriseFromConsole();
