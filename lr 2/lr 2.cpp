#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define LENNAME 100
#define LENDATE 15
#define LENINDUSTRY 25

struct Сontinent
{
    char nameOfContinent[LENNAME];
    int numberOfCountries;
    char* listOfCountries[LENNAME];
    int squareOfContinent;
};

struct Country
{
    char nameOfCountry[LENNAME];
    int numberOfSubject;
    char* listOfSubject[LENNAME];
    int netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    int incomeOfCountry;
    int expensesOfCountry;
    int budgetDeficitOrSurplusOfCountry;
};

struct Subject
{
    char nameOfSubject[LENNAME];
    char* listOfCities[LENNAME];
    int populationOfSubject;
    int squareOfSubject;
};

struct City
{
    char nameOfCity[LENNAME];
    char* listOfEnterprises[LENNAME];
    int populationOfCity;
    int numberOfEnterprises;
};

struct Enterprise
{
    char nameOfEnterprise[LENNAME];
    char citySubjectCoutry[LENNAME * 3];
    int turnoverPerYear;
    int netProfitOfEnterprise;
    char dateOfFoundationEnterprise[LENDATE];
    char industryOfEnterprise[LENINDUSTRY];
};

int main()
{
    
}
