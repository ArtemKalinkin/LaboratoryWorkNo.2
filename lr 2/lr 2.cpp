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
#define MAXCONTINENTS 6
#define MAXCOUNTRIES 10
#define MAXSUBJECTS 10
#define MAXCITIES 10
#define MAXENTERPRISES 10


int numberOfContinentsEntered = 0;



struct Enterprise
{
    char *nameOfEnterprise;
    char *citySubjectCountry;
    unsigned long turnoverPerYear;
    long netProfitOfEnterprise;
    char *dateOfFoundationEnterprise;
    char *industryOfEnterprise;
};

struct City
{
    char *nameOfCity;
    int populationOfCity;
    int numberOfEnterprises;
    Enterprise listOfEnterprises[MAXENTERPRISES];
};

struct Subject
{
    char *nameOfSubject;
    int numberOfCities;
    int populationOfSubject;
    int squareOfSubject;
    City listOfCities[MAXCITIES];
};

struct Country
{
    char *nameOfCountry;
    int numberOfSubjects;
    unsigned long netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    unsigned long incomeOfCountry;
    unsigned long expensesOfCountry;
    long budgetDeficitOrSurplusOfCountry;
    Subject listOfSubjects[MAXSUBJECTS];
};

struct Сontinent
{
    char* nameOfContinent;
    int numberOfCountries;
    int squareOfContinent;
    Country listOfCountries[MAXCOUNTRIES];
};

void initializationContinent(struct Сontinent *pointerContinent);
void initializationCountry(struct Country* pointerCountry);
void initializationSubject(struct Subject* pointerSubject);
void initializationCity(struct City* pointerCity);
void initializationEnterprise(struct Enterprise* pointerEnterprise);
void initializationContinent(struct Сontinent* pointerContinent, int number, int square, const char name[], struct Country *countries[]);
void initializationCountry(struct Country* pointerCountry, int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, const char name[], struct Subject *subjects[]);
void initializationSubject(struct Subject* pointerSubject, int population, int square, int number, const char  name[], struct City *cities[]);
void initializationCity(struct City* pointerCity, int population, int number, const char name[], struct Enterprise *enterprises[]);
void initializationEnterprise(struct Enterprise* pointerEnterprise, int profit, int turnover, const char address[], const char date[], const char industry[], const char name[]);
void initializationAllStructures(struct Сontinent continents[]);
void inputAllStructures(struct Сontinent continents[]);
void inputСontinentFromConsole(struct Сontinent* pointerContinent);
void inputCountryFromConsole(struct Country* pointerCountry);
void inputSubjectFromConsole(struct Subject* pointerSubject);
void inputCityFromConsole(struct City* pointerCity);
void inputEnterpriseFromConsole(struct Enterprise* pointerEnterprise);
void outputContinentToConsole(struct Сontinent continent, int number);
void outputCountryToConsole(struct Country country, int number);
void outputSubjectToConsole(struct Subject subject, int number);
void outputCityToConsole(struct City city, int number);
void outputEnterpriseToConsole(struct Enterprise enterprise, int number);
void continentTableHeader();
void countryTableHeader();
void subjectTableHeader();
void cityTableHeader();
void enterpriseTableHeader();
int calculatingProfitsFromEnterprises(struct Country* pointerCountry);
int comparisonOfTwoCountries(struct Country* firstCountry, struct Country* secondCountry);
int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b);
int choosingContinent(struct Сontinent continents[]);
int choosingCountry(struct Country countries[]);
int choosingSubject(struct Subject subjects[]);
int choosingCity(struct City cities[]);


void deletingNewlineTransitionCharacter(char* line);
int protectionAgainstIncorrectTextInput(char* line);
int checkingForCorrectnessOfDateEntry(char* date);




struct Сontinent listOfContinents[MAXCONTINENTS];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    char character;
    int number;
    int numberOfContinent;
    int numberOfCountry;
    int numberOfSubject;
    int numberOfCity;
    int numberOfEnterprise;
    int i, n;
    int numberFirst, numberSecond;
    initializationAllStructures(listOfContinents);
    inputAllStructures(listOfContinents);
    puts("Вывести на экран:");
    puts("1.Все континенты");
    puts("2.Все страны определенного континента");
    puts("3.Все субъекты определенной страны");
    puts("4.Все города определенного субъекта");
    puts("5.Все предприятия определенного города");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > 5));
    switch (number)
    {
    case 1:
        continentTableHeader();
        for (i = 0; i < numberOfContinentsEntered; i++)
            outputContinentToConsole(listOfContinents[i], i);
        break;
    case 2: 
        numberOfContinent = choosingContinent(listOfContinents);
        i = 0;
        countryTableHeader();
        while ((listOfContinents[numberOfContinent].listOfCountries[i].nameOfCountry != NULL) && (i < MAXCOUNTRIES)) {
            outputCountryToConsole(listOfContinents[numberOfContinent].listOfCountries[i], i);
            i++;
        }
        break;
    case 3: 
        numberOfContinent = choosingContinent(listOfContinents);
        numberOfCountry = choosingCountry(listOfContinents[numberOfContinent].listOfCountries);
        i = 0;
        subjectTableHeader();
        while ((listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[i].nameOfSubject != NULL) && (i < MAXSUBJECTS)) {
            outputSubjectToConsole(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[i], i);
            i++;
        }
        break;
    case 4: 
        numberOfContinent = choosingContinent(listOfContinents);
        numberOfCountry = choosingCountry(listOfContinents[numberOfContinent].listOfCountries);
        numberOfSubject = choosingSubject(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects);
        i = 0;
        cityTableHeader();
        while ((listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[i].listOfCities[i].nameOfCity != NULL) && (i < MAXCITIES)) {
            outputCityToConsole(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[i].listOfCities[i], i);
            i++;
        }
        break;
    case 5: 
        numberOfContinent = choosingContinent(listOfContinents);
        numberOfCountry = choosingCountry(listOfContinents[numberOfContinent].listOfCountries);
        numberOfSubject = choosingSubject(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects);
        numberOfCity = choosingCity(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[numberOfSubject].listOfCities);
        i = 0;
        enterpriseTableHeader();
        while ((listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[numberOfSubject].listOfCities[numberOfCity].listOfEnterprises[i].nameOfEnterprise != NULL) && (i < MAXENTERPRISES)) {
            outputEnterpriseToConsole(listOfContinents[numberOfContinent].listOfCountries[numberOfCountry].listOfSubjects[numberOfSubject].listOfCities[numberOfCity].listOfEnterprises[i], i);
            i++;
        }
        break;
    default:
        break;
    }
    puts("\n\n\n\nСРАВНЕНИЕ ДВУХ СТРАН\n");
    numberOfContinent = choosingContinent(listOfContinents);
    i = 0;
    countryTableHeader();
    while ((listOfContinents[numberOfContinent].listOfCountries[i].nameOfCountry != NULL) && (i < MAXCOUNTRIES)) {
        outputCountryToConsole(listOfContinents[numberOfContinent].listOfCountries[i], i);
        i++;
    }
    n = i;
    do {
        printf("Введите номер первой страны в списке: ");
        scanf("%d", &numberFirst);
        if ((numberFirst < 1) || (numberFirst > n))
            puts("Страны с данным номером нет в списке");
    } while ((numberFirst < 1) || (numberFirst > n));
    do {
        printf("Введите номер второй страны в списке: ");
        scanf("%d", &numberSecond);
        if ((numberSecond < 1) || (numberSecond > n))
            puts("Страны с данным номером нет в списке");
        if (numberSecond == numberFirst)
            puts("Данная страна уже выбрана");
    } while ((numberSecond < 1) || (numberSecond > n) || (numberSecond == numberFirst));
    // Работа с динамическими переменными данных типов
    struct Enterprise* enterprises[MAXENTERPRISES];
    struct City* cities[MAXCITIES];
    struct Subject* subjects[MAXSUBJECTS];
    struct Country* theCountryOne = (struct Country*)malloc(sizeof(struct Country));
    if (theCountryOne == NULL) {
        puts("Ошибка при выделение памяти!");
        return -2;
    }
    struct Country* theCountryTwo = (struct Country*)malloc(sizeof(struct Country));
    if (theCountryTwo == NULL) {
        puts("Ошибка при выделение памяти!");
        return -2;
    }
    *theCountryOne = listOfContinents[numberOfContinent].listOfCountries[numberFirst - 1];
    *theCountryTwo = listOfContinents[numberOfContinent].listOfCountries[numberSecond - 1];
    if (comparisonOfTwoCountries(theCountryOne, theCountryTwo) == 1)
        printf("\nПо общим показателям страна - %s лучше страны - %s\n", theCountryOne->nameOfCountry, theCountryTwo->nameOfCountry);
    else
        printf("\nПо общим показателям страна - %s лучше страны - %s\n", theCountryTwo->nameOfCountry, theCountryOne->nameOfCountry);
    struct Сontinent* theContinent = (struct Сontinent*)malloc(sizeof(struct Сontinent));
    if (theContinent == NULL) {
        puts("Ошибка при выделение памяти!");
        return -2;
    }
    *theContinent = listOfContinents[0];
    for (i = 1; i < numberOfContinentsEntered; i++) {
        if (listOfContinents[i].numberOfCountries > theContinent->numberOfCountries)
            *theContinent = listOfContinents[i];
    }
    printf("\nКонтинент с наибольшим количество стран - %s\n\n", theContinent->nameOfContinent);
    for (i = 0; i < MAXCITIES; i++) {
        cities[i] = (struct City*)calloc(1, sizeof(struct City));
        initializationCity(cities[i]);
        if (cities[i] == NULL) {
            puts("Ошибка при выделение памяти!");
            return -2;
        }
    }
    for (i = 0; i < MAXENTERPRISES; i++) {
        enterprises[i] = (struct Enterprise*)calloc(1, sizeof(struct Enterprise));
        initializationEnterprise(enterprises[i]);
        if (enterprises[i] == NULL) {
            puts("Ошибка при выделение памяти!");
            return -2;
        }
    }
    for (i = 0; i < MAXSUBJECTS; i++) {
        subjects[i] = (struct Subject*)calloc(1, sizeof(struct Subject));
        initializationSubject(subjects[i]);
        if (subjects[i] == NULL) {
            puts("Ошибка при выделение памяти!");
            return -2;
        }
    }
    initializationEnterprise(enterprises[0], 5500000, 39000000, "Россия, Приморский край, Владивосток", "25.08.2020", "Пищевая", "Онигири");
    enterpriseTableHeader();
    outputEnterpriseToConsole(*enterprises[0], 0);
    puts("\n");
    initializationCity(cities[0], 597240, 200, "Владивосток", enterprises);
    cityTableHeader();
    outputCityToConsole(*cities[0], 0);
    puts("\n");
    subjects[0] = (struct Subject*)malloc(sizeof(struct Subject));
    initializationSubject(subjects[0], 1820076, 164673, 12, "Приморский край", cities);
    subjectTableHeader();
    outputSubjectToConsole(*subjects[0], 0);
    for (i = 0; i < MAXENTERPRISES; i++)
        free(enterprises[i]);
    for (i = 0; i < MAXCITIES; i++)
        free(cities[i]);
    for (i = 0; i < MAXSUBJECTS; i++)
        free(subjects[i]);
    free(theContinent);
    free(theCountryOne);
    free(theCountryTwo);
    //clearingAllMemory(listOfContinents);
    return 0;     
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
    if ((!isdigit(date[3])) || (!isdigit(date[4]))) {
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

void initializationContinent(struct Сontinent* pointerContinent) {
    pointerContinent->numberOfCountries = 0;
    pointerContinent->squareOfContinent = 0;
    pointerContinent->nameOfContinent = NULL;
}

void initializationCountry(struct Country* pointerCountry) {
    pointerCountry->budgetDeficitOrSurplusOfCountry = 0;
    pointerCountry->expensesOfCountry = 0;
    pointerCountry->incomeOfCountry = 0;
    pointerCountry->netProfitCountryEnterprises = 0;
    pointerCountry->numberOfSubjects = 0;
    pointerCountry->populationOfCountry = 0;
    pointerCountry->squareOfCountry = 0;
    pointerCountry->nameOfCountry = NULL;
}

void initializationSubject(struct Subject* pointerSubject) {
    pointerSubject->populationOfSubject = 0;
    pointerSubject->squareOfSubject = 0;
    pointerSubject->numberOfCities = 0;
    pointerSubject->nameOfSubject = NULL;
}

void initializationCity(struct City* pointerCity) {
    pointerCity->populationOfCity = 0;
    pointerCity->numberOfEnterprises = 0;
    pointerCity->nameOfCity = NULL;
}

void initializationEnterprise(struct Enterprise* pointerEnterprise) {
    pointerEnterprise->netProfitOfEnterprise = 0;
    pointerEnterprise->turnoverPerYear = 0;
    pointerEnterprise->citySubjectCountry = NULL;
    pointerEnterprise->dateOfFoundationEnterprise = NULL;
    pointerEnterprise->industryOfEnterprise = NULL;
    pointerEnterprise->nameOfEnterprise = NULL;
}


// Инициализация структур с параметрами

void initializationContinent(struct Сontinent* pointerContinent, int number, int square, const char name[], struct Country *countries[]) {
    int i;
    int lenOfName = strlen(name);
    pointerContinent->nameOfContinent = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerContinent->nameOfContinent, name);
    pointerContinent->numberOfCountries = number;
    pointerContinent->squareOfContinent = square;
    i = 0;
    while (i < MAXCOUNTRIES) {
        if ((*countries)[i].nameOfCountry != NULL)
            pointerContinent->listOfCountries[i] = *countries[i];
        else
            initializationCountry(&pointerContinent->listOfCountries[i]);
        i++;
    }
}

void initializationCountry(struct Country* pointerCountry, int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, const char name[], struct Subject *subjects[]) {
    int i;
    int lenOfName = strlen(name);
    pointerCountry->nameOfCountry = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerCountry->nameOfCountry, name);
    pointerCountry->budgetDeficitOrSurplusOfCountry = budget;
    pointerCountry->expensesOfCountry = expenses;
    pointerCountry->incomeOfCountry = income;
    pointerCountry->netProfitCountryEnterprises = profitEnterprises;
    pointerCountry->numberOfSubjects = number;
    pointerCountry->populationOfCountry = population;
    pointerCountry->squareOfCountry = square;
    i = 0;
    while (i < MAXSUBJECTS) {
        if ((*subjects)[i].nameOfSubject != NULL)
            pointerCountry->listOfSubjects[i] = *subjects[i];
        else
            initializationSubject(&pointerCountry->listOfSubjects[i]);
        i++;
    }
}

void initializationSubject(struct Subject* pointersubject, int population, int square, int number, const char name[], struct City *cities[]) {
    int i;
    int lenOfName = strlen(name);
    pointersubject->nameOfSubject = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointersubject->nameOfSubject, name);
    pointersubject->populationOfSubject = population;
    pointersubject->squareOfSubject = square;
    pointersubject->numberOfCities = number;
    i = 0;
    while (i < MAXCITIES) {
        if ((*cities)[i].nameOfCity != NULL)
            pointersubject->listOfCities[i] = *cities[i];
        else
            initializationCity(&pointersubject->listOfCities[i]);
        i++;
    }
}

void initializationCity(struct City* pointerCity, int population, int number,const char name[], struct Enterprise *enterprises[]) {
    int i;
    int lenOfName = strlen(name);
    pointerCity->nameOfCity = (char*)calloc(lenOfName, sizeof(char));
    strcpy(pointerCity->nameOfCity, name);
    pointerCity->populationOfCity = population;
    pointerCity->numberOfEnterprises = number;
    i = 0;
    while (i < MAXENTERPRISES) {
        if ((*enterprises)[i].nameOfEnterprise != NULL)
            pointerCity->listOfEnterprises[i] = *enterprises[i];
        else
            initializationEnterprise(&pointerCity->listOfEnterprises[i]);
        i++;
    }
}

void initializationEnterprise(struct Enterprise* pointerEnterprise, int profit, int turnover, const char address[], const char date[], const char industry[],const char name[]) {
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
    pointerEnterprise->citySubjectCountry = (char*)calloc(length, sizeof(char));
    strcpy(pointerEnterprise->citySubjectCountry, address);
    pointerEnterprise->netProfitOfEnterprise = profit;
    pointerEnterprise->turnoverPerYear = turnover;
}

// Инициализация всех структур без параметров
void initializationAllStructures(struct Сontinent continents[]) {
    for (int i = 0; i < MAXCONTINENTS; i++) {
        initializationContinent(&continents[i]);
        for (int j = 0; j < MAXCOUNTRIES; j++) {
            initializationCountry(&continents[i].listOfCountries[j]);
            for (int k = 0; k < MAXSUBJECTS; k++) {
                initializationSubject(&continents[i].listOfCountries[j].listOfSubjects[k]);
                for (int x = 0; x < MAXCITIES; x++) {
                    initializationCity(&continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x]);
                    for (int z = 0; z < MAXENTERPRISES; z++)
                        initializationEnterprise(&continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z]);
                }
            }
        }
    }
}


// Ввод из консоли
void inputСontinentFromConsole(struct Сontinent* pointerContinent) {
    char name[LENNAME];
    int number;
    int square;
    int i, length;
    char* temp;
    puts("ВВОД КОНТИНЕНТА\n");
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
    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(pointerContinent->nameOfContinent, length * sizeof(char));
    pointerContinent->nameOfContinent = temp;
    strcpy(pointerContinent->nameOfContinent, name);
    pointerContinent->numberOfCountries = number;
    pointerContinent->squareOfContinent = square;
}


void inputCountryFromConsole(struct Country* pointerCountry) {
    char name[LENNAME];
    int number;
    int square;
    unsigned long income;
    unsigned long expenses;
    long budget;
    int population;
    int i, length;
    char* temp;
    puts("\nВВОД СТРАНЫ\n");
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

    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(pointerCountry->nameOfCountry, length * sizeof(char));
    pointerCountry->nameOfCountry = temp;
    strcpy(pointerCountry->nameOfCountry, name);
    pointerCountry->populationOfCountry = population;
    pointerCountry->numberOfSubjects = number;
    pointerCountry->squareOfCountry = square;
    pointerCountry->incomeOfCountry = income;
    pointerCountry->expensesOfCountry = expenses;
    pointerCountry->budgetDeficitOrSurplusOfCountry = income - expenses;
}

void inputSubjectFromConsole(struct Subject* pointerSubject) {
    char name[LENNAME];
    int number;
    int square;
    int population;
    int i, length;
    char* temp;
    puts("\nВВОД СУБЪЕКТА\n");
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
    temp = (char*)realloc(pointerSubject->nameOfSubject, length * sizeof(char));
    pointerSubject->nameOfSubject = temp;
    strcpy(pointerSubject->nameOfSubject, name);
    pointerSubject->numberOfCities = number;
    pointerSubject->squareOfSubject = square;
    pointerSubject->populationOfSubject = population;
}


void inputCityFromConsole(struct City* pointerCity) {
    char name[LENNAME];
    int number;
    int population;
    int i, length;
    char* temp;
    puts("\nВВОД ГОРОДА\n");
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
    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(pointerCity->nameOfCity, length * sizeof(char));
    pointerCity->nameOfCity = temp;
    strcpy(pointerCity->nameOfCity, name);
    pointerCity->numberOfEnterprises = number;
    pointerCity->populationOfCity = population;
}

void inputEnterpriseFromConsole(struct Enterprise* pointerEnterprise) {
    char name[LENNAME];
    long turnover;
    long profit;
    char date[20];
    char industry[LENNAME];
    int i, length;
    char* temp;
    puts("\nВВОД ПРЕДПРИЯТИЯ\n");
    do {
        puts("Введите название предприятия:");
        fgets(name, LENNAME, stdin);
    } while (protectionAgainstIncorrectTextInput(name));
    deletingNewlineTransitionCharacter(name);
    do {
        do {
            puts("Введите дату основания предприятия:");
            fgets(date, 20, stdin);
        } while (protectionAgainstIncorrectTextInput(date));
    } while (checkingForCorrectnessOfDateEntry(date));
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
    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(pointerEnterprise->nameOfEnterprise, length* sizeof(char));
    pointerEnterprise->nameOfEnterprise = temp;
    temp = NULL;
    strcpy(pointerEnterprise->nameOfEnterprise, name);
    temp = (char*)realloc(pointerEnterprise->citySubjectCountry, LENNAME * 3 * sizeof(char));
    pointerEnterprise->citySubjectCountry = temp;
    temp = NULL;
    length = strlen(date);
    temp = (char*)realloc(pointerEnterprise->dateOfFoundationEnterprise, length * sizeof(char));
    pointerEnterprise->dateOfFoundationEnterprise = temp;
    temp = NULL;
    strcpy(pointerEnterprise->dateOfFoundationEnterprise, date);
    length = strlen(industry);
    temp = (char*)realloc(pointerEnterprise->industryOfEnterprise, length * sizeof(char));
    pointerEnterprise->industryOfEnterprise = temp;
    temp = NULL;
    strcpy(pointerEnterprise->industryOfEnterprise, industry);
    pointerEnterprise->turnoverPerYear = turnover;
    pointerEnterprise->netProfitOfEnterprise = profit;
    pointerEnterprise->citySubjectCountry = (char*)calloc(3 * LENNAME, sizeof(char));
}

void inputAllStructures(struct Сontinent continents[]) {
    int numberOfCountriesEntered = 0;
    int numberOfSubjectsEntered = 0;
    int i, j, k, x, z;
    i = 0;
    if (numberOfContinentsEntered != MAXCONTINENTS) {
        do {
            inputСontinentFromConsole(&continents[i]);
            numberOfContinentsEntered++;
            j = 0;
            do {
                inputCountryFromConsole(&continents[i].listOfCountries[j]);
                numberOfCountriesEntered++;
                k = 0;
                do {
                    inputSubjectFromConsole(&continents[i].listOfCountries[j].listOfSubjects[k]);
                    numberOfSubjectsEntered++;
                    x = 0;
                    do {
                        inputCityFromConsole(&continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x]);
                        z = 0;
                        do {
                            inputEnterpriseFromConsole(&continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z]);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].nameOfCountry);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, ", ");
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].listOfSubjects[k].nameOfSubject);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, ", ");
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].nameOfCity);
                            puts("Для завершения ввода предприятий нажмите Esc.");
                            puts("Для продолжения любую другую клавишу.\n");
                            z++;
                        } while (_getch() != 27);
                        puts("Для завершения ввода городов нажмите Esc.");
                        puts("Для продолжения любую другую клавишу.\n");
                        x++;
                    } while (_getch() != 27);
                    if (numberOfSubjectsEntered == MAXSUBJECTS)
                        puts("Вы ввели максимальное количество субъектов для одной страны!");
                    else {
                        puts("Для завершения ввода субъектов нажмите Esc.");
                        puts("Для продолжения любую другую клавишу.\n");
                    }
                    k++;
                } while ((_getch() != 27) && (numberOfSubjectsEntered != MAXSUBJECTS));
                if (numberOfCountriesEntered == MAXCOUNTRIES)
                    puts("Вы ввели максимальное количество стан для одного континета!");
                else {
                    puts("Для завершения ввода стран нажмите Esc.");
                    puts("Для продолжения любую другую клавишу.\n");
                }
                continents[i].listOfCountries[j].netProfitCountryEnterprises = calculatingProfitsFromEnterprises(&continents[i].listOfCountries[j]);
                j++;
            } while ((_getch() != 27) && (numberOfCountriesEntered != MAXCOUNTRIES));
            if (numberOfContinentsEntered == MAXCONTINENTS)
                puts("Вы ввели все существующие континеты!");
            else {
                puts("Для завершения ввода континетов нажмите Esc.");
                puts("Для продолжения любую другую клавишу.\n");
            }
            i++;
        } while ((_getch() != 27) && (numberOfContinentsEntered != MAXCONTINENTS));
    }
}



// Функции вывода

void outputContinentToConsole(struct Сontinent continent, int number) {
    int i;
    printf("* %-5d * %-18s * %-16d * %-18d * ", number + 1, continent.nameOfContinent, continent.numberOfCountries, continent.squareOfContinent);
    printf("%-30s *\n", continent.listOfCountries[0].nameOfCountry);
    i = 1;
    while ((continent.listOfCountries[i].nameOfCountry != NULL) && (i < MAXCOUNTRIES)) {
        printf("*       *                    *                  *                    * %-30s *\n", continent.listOfCountries[i].nameOfCountry);
        i++;
    }
    printf("*******************************************************************************************************\n");
}

void outputCountryToConsole(struct Country country, int number) {
    int i;
    printf("* %-5d * %-18s * %-20d * %-14d * ", number + 1, country.nameOfCountry, country.numberOfSubjects, country.squareOfCountry);
    printf("%-9d * %-19d * %-14lu * ", country.populationOfCountry, country.netProfitCountryEnterprises, country.incomeOfCountry);
    printf("%-15lu * %-24ld * ", country.expensesOfCountry, country.budgetDeficitOrSurplusOfCountry);
    printf("%-25s *\n", country.listOfSubjects[0].nameOfSubject);
    i = 1;
    while ((country.listOfSubjects[i].nameOfSubject != NULL) && (i < MAXSUBJECTS)) {
        printf("*       *                    *                      *                *           *                     *                *                 *                          * %-25s *\n", country.listOfSubjects[i].nameOfSubject);
        i++;
    }
    printf("**************************************************************************************************************************************************************************************************\n");
}

void outputSubjectToConsole(struct Subject subject, int number) {
    int i;
    printf("* %-5d * %-18s * %-18d * ", number + 1, subject.nameOfSubject, subject.numberOfCities);
    printf("%-16d * %-9d * ", subject.squareOfSubject, subject.populationOfSubject);
    printf("%-28s *\n", subject.listOfCities[0].nameOfCity);
    i = 1;
    while ((subject.listOfCities[i].nameOfCity != NULL) && (i < MAXCITIES)) {
        printf("*       *                    *                    *                  *           * %-28s *\n", subject.listOfCities[i].nameOfCity);
    }
    printf("*****************************************************************************************************************\n");

}
void outputCityToConsole(struct City city, int number) {
    int i;
    printf("* %-5d * %-18s * %-22d * %-9d * ", number + 1, city.nameOfCity, city.numberOfEnterprises, city.populationOfCity);
    printf("%-36s *\n", city.listOfEnterprises[0].nameOfEnterprise);
    i = 1;
    while ((city.listOfEnterprises[i].nameOfEnterprise != NULL) && (i < MAXENTERPRISES)) {
        printf("*       *                    *                        *           * %-36s *\n", city.listOfEnterprises[i].nameOfEnterprise);
        i++;
    }
    printf("**********************************************************************************************************\n");
}
void outputEnterpriseToConsole(struct Enterprise enterprise, int number) {
    printf("* %-5d * %-23s * %-47s * ", number + 1, enterprise.nameOfEnterprise, enterprise.citySubjectCountry);
    printf("%-17lu * %-13ld * ", enterprise.turnoverPerYear, enterprise.netProfitOfEnterprise);
    printf("%-24s * %-14s *\n", enterprise.industryOfEnterprise, enterprise.dateOfFoundationEnterprise);
    printf("*********************************************************************************************************************************************************************\n");
}

// Шапки таблиц

void continentTableHeader() {
    printf("*******************************************************************************************************\n");
    printf("* Номер *     Континент      * Количество стран * Площадь континента *          Список стран          *\n");
    printf("*******************************************************************************************************\n");
}
void countryTableHeader() {
    printf("**************************************************************************************************************************************************************************************************\n");
    printf("* Номер *       Страна       * Количество субъектов * Площадь страны * Население * Прибыль предприятий *     Доходы     *     Расходы     * Профицит/дефицит бюджета *      Список субъектов     *\n");
    printf("**************************************************************************************************************************************************************************************************\n");
}
void subjectTableHeader() {
    printf("*****************************************************************************************************************\n");
    printf("* Номер *       Субъект      * Количество городов * Площадь субъекта * Население *        Список городов        *\n");
    printf("*****************************************************************************************************************\n");
}
void cityTableHeader() {
    printf("**********************************************************************************************************\n");
    printf("* Номер *       Город        * Количество предприятий * Население *          Список предприятий          *\n");
    printf("**********************************************************************************************************\n");
}
void enterpriseTableHeader() {
    printf("*********************************************************************************************************************************************************************\n");
    printf("* Номер *       Предприятие       *                  Местоположение                 *   Оборот за год   *    Прибыль    *          Отрасль         * Дата основания *\n");
    printf("*********************************************************************************************************************************************************************\n");
}


// Вычисление прибыли предпритий страны

int calculatingProfitsFromEnterprises(struct Country* pointerCountry) {
    int i, j, k;
    int numberOfProfit = 0;
    for (i = 0; i < MAXSUBJECTS; i++) {
        for (j = 0; j < MAXCITIES; j++) {
            for (k = 0; k < MAXENTERPRISES; k++) {
                numberOfProfit += pointerCountry->listOfSubjects[i].listOfCities[j].listOfEnterprises[k].netProfitOfEnterprise;
            }
        }
    }
    return numberOfProfit;
}

//Сравнение характеристик двух стран

int comparisonOfTwoCountries(struct Country* firstCountry, struct Country* secondCountry) {
    int percentageOfSquare;
    int percentageOfPopulation;
    int percentageOfProfits;
    int percentageOfIncome;
    int percentageOfExpenses;
    int numberOne = 0, numberTwo = 0;
    int value;
    puts("\n");
    countryTableHeader();
    outputCountryToConsole(*firstCountry, 0);
    outputCountryToConsole(*secondCountry, 1);
    puts("\nПроцентное соотношение характеристик стран");
    printf("%s     %s\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry);
    // Площадь
    if (firstCountry->squareOfCountry > secondCountry->squareOfCountry) {
        percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->squareOfCountry, secondCountry->squareOfCountry);
        printf("Площадь страны - %s больше площади страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfSquare);
        numberOne++;
    }
    else if (firstCountry->squareOfCountry < secondCountry->squareOfCountry) {
        percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->squareOfCountry, firstCountry->squareOfCountry);
        printf("Площадь страны - %s больше площади страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfSquare);
        numberTwo++;
    }
    else
        printf("Площади стран равны\n");
    // Население
    if (firstCountry->populationOfCountry > secondCountry->populationOfCountry) {
        percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->populationOfCountry, secondCountry->populationOfCountry);
        printf("Населeние страны - %s больше населения страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfPopulation);
        numberOne++;
    }
    else  if (firstCountry->populationOfCountry < secondCountry->populationOfCountry) {
        percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->populationOfCountry, firstCountry->populationOfCountry);
        printf("Населeние страны - %s больше населения страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfPopulation);
        numberTwo++;
    }
    else
        printf("Население стран равно");
    //Прибыль предприятий 
    if (firstCountry->netProfitCountryEnterprises > secondCountry->netProfitCountryEnterprises) {
        percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->netProfitCountryEnterprises, secondCountry->netProfitCountryEnterprises);
        printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfProfits);
        numberOne++;
    }
    else if (firstCountry->netProfitCountryEnterprises < secondCountry->netProfitCountryEnterprises) {
        percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->netProfitCountryEnterprises, firstCountry->netProfitCountryEnterprises);
        printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfProfits);
        numberTwo++;
    }
    else printf("Прибыли предприятий стран равны\n");
    // Доходы
    if (firstCountry->incomeOfCountry > secondCountry->incomeOfCountry) {
        percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->incomeOfCountry, secondCountry->incomeOfCountry);
        printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfIncome);
        numberOne++;
    }
    else if (firstCountry->incomeOfCountry < secondCountry->incomeOfCountry) {
        percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->incomeOfCountry, firstCountry->incomeOfCountry);
        printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfIncome);
        numberTwo++;
    }
    else
        printf("Доходы стран равны\n");
    // Расходы
    if (firstCountry->expensesOfCountry > secondCountry->expensesOfCountry) {
        percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->expensesOfCountry, secondCountry->expensesOfCountry);
        printf("Расходы страны - %s больше доходов страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfExpenses);
    }
    else if (firstCountry->expensesOfCountry < secondCountry->expensesOfCountry) {
        percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->expensesOfCountry, firstCountry->expensesOfCountry);
        printf("Расходы страны - %s больше расходов страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfExpenses);
    }
    else
        printf("Расходы стран равны\n");
    if (numberOne > numberTwo)
        value = 1;
    else
        value = 2;
    return value;
}

int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b) {
    int result;
    result = (a - b) / b * 100;
    return result;
}

int choosingContinent(struct Сontinent continents[]){
    int i, number;
    char character;
    continentTableHeader();
    for (i = 0; i < numberOfContinentsEntered; i++)
        outputContinentToConsole(continents[i], i);
    puts("\nВыберите континент\n");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > numberOfContinentsEntered + 1));
    return number - 1;

}

int choosingCountry(struct Country countries[]) {
    int i, n, number;
    char character;
    countryTableHeader();
    i = 0;
    while (countries[i].nameOfCountry != NULL) {
        outputCountryToConsole(countries[i], i);
        i++;
    }
    n = i + 1;
    puts("\nВыберите страну\n");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > n));
    return number - 1;
}

int choosingSubject(struct Subject subjects[]) {
    int i, n, number;
    char character;
    subjectTableHeader();
    i = 0;
    while (subjects[i].nameOfSubject != NULL) {
        outputSubjectToConsole(subjects[i], i);
        i++;
    }
    n = i + 1;
    puts("\nСубъект\n");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > n));
    return number - 1;
}

int choosingCity(struct City cities[]) {
    int i, n, number;
    char character;
    cityTableHeader();
    i = 0;
    while (cities[i].nameOfCity != NULL) {
        outputCityToConsole(cities[i], i);
        i++;
    }
    n = i + 1;
    puts("\nВыберите город\n");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > n));
    return number - 1;
}