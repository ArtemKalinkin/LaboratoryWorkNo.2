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
#define MAXCOUNTRIES 5
#define MAXSUBJECTS 45
#define MAXCITIES 15
#define MAXENTERPRISES 50

int numberOfContinentsEntered = 0;

typedef struct Сontinent
{
    char* nameOfContinent;
    int numberOfCountries;
    int squareOfContinent;
    Country listOfCountries[MAXCOUNTRIES];
};

typedef struct Country
{
    char *nameOfCountry;
    int numberOfSubjects;
    int netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    int incomeOfCountry;
    int expensesOfCountry;
    int budgetDeficitOrSurplusOfCountry;
    Subject listOfSubjects[MAXSUBJECTS];
};

typedef struct Subject
{
    char *nameOfSubject;
    int numberOfCities;
    int populationOfSubject;
    int squareOfSubject;
    City listOfCities[MAXCITIES];
};

typedef struct City
{
    char *nameOfCity;
    int populationOfCity;
    int numberOfEnterprises;
    Enterprise listOfEnterprises[MAXENTERPRISES];
};

typedef struct Enterprise
{
    char *nameOfEnterprise;
    char *citySubjectCountry;
    int turnoverPerYear;
    int netProfitOfEnterprise;
    char *dateOfFoundationEnterprise;
    char *industryOfEnterprise;
};


void initializationContinent(Сontinent continent);
void initializationCountry(Country country);
void initializationSubject(Subject subject);
void initializationCity(City city);
void initializationEnterprise(Enterprise enterprise);
void initializationContinent(Сontinent continent, int number, int square, char *name, Country countries[]);
void initializationCountry(Country country,int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char *name, Subject subjects[]);
void initializationSubject(Subject subject, int population, int square, int number, char * name, City cities[]);
void initializationCity(City city, int population, int number, char *name, Enterprise enterprises[]);
void initializationEnterprise(Enterprise enterprise, int profit, int turnover, char *address, char* date, char* industry, char* name);
void initializationAllStructures(Сontinent continents[]);
void inputAllStructures(Сontinent continents[]);
void inputСontinentFromConsole(Сontinent continent);
void inputCountryFromConsole(Country country);
void inputSubjectFromConsole(Subject subject);
void inputCityFromConsole(City city);
void inputEnterpriseFromConsole(Enterprise enterprise);
void outputContinentToConsole(Сontinent continent, int number);
void outputCountryToConsole(Country country, int number);
void outputSubjectToConsole(Subject subject, int number);
void outputCityToConsole(City city, int number);
void outputEnterpriseToConsole(Enterprise enterprise, int number);
void continentTableHeader();
void countryTableHeader();
void subjectTableHeader();
void cityTableHeader();
void enterpriseTableHeader();
int calculatingProfitsFromEnterprises(Country country);
void comparisonOfTwoCountries(Country* firstCountry, Country* secondCountry);
int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(int a, int b);


void deletingNewlineTransitionCharacter(char* line);
int protectionAgainstIncorrectTextInput(char* line);
int checkingForCorrectnessOfDateEntry(char* date);



Сontinent listOfContinents[MAXCONTINENTS];


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    char character;
    int number;
    initializationAllStructures(listOfContinents);
    inputAllStructures(listOfContinents);
    puts("Вывести на экран:");
    puts("1.Все континеты");
    puts("2.Все страны определенного континета");
    puts("3.Все субъекты определенной страны");
    puts("4.Все города определенного субъекта");
    puts("5.Все предприятия определенного города");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > 5));
    continentTableHeader();
    for (int i = 0; i < numberOfContinentsEntered; i++)
        outputContinentToConsole(listOfContinents[i], i);
    if (number > 1) {
        void;
    }
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

void initializationContinent(Сontinent continent) {
    continent.numberOfCountries = 0;
    continent.squareOfContinent = 0;
    continent.nameOfContinent = NULL;
    //continent.listOfCountries = { NULL };
}

void initializationCountry(Country country) {
    country.budgetDeficitOrSurplusOfCountry = 0;
    country.expensesOfCountry = 0;
    country.incomeOfCountry = 0;
    country.netProfitCountryEnterprises = 0;
    country.numberOfSubjects = 0;
    country.populationOfCountry = 0;
    country.squareOfCountry = 0;
    country.nameOfCountry = NULL;
    //country.listOfSubjects = { NULL };
}

void initializationSubject(Subject subject) {
    subject.populationOfSubject = 0;
    subject.squareOfSubject = 0;
    subject.numberOfCities = 0;
    subject.nameOfSubject = NULL;
    //subject.listOfCities = { NULL };
}

void initializationCity(City city) {
    city.populationOfCity = 0;
    city.numberOfEnterprises = 0;
    city.nameOfCity = NULL;
    //city.listOfEnterprises = { NULL };
}

void initializationEnterprise(Enterprise enterprise) {
    enterprise.netProfitOfEnterprise = 0;
    enterprise.turnoverPerYear = 0;
    enterprise.citySubjectCountry = NULL;
    enterprise.dateOfFoundationEnterprise = NULL;
    enterprise.industryOfEnterprise = NULL;
    enterprise.nameOfEnterprise = NULL;
}


// Инициализация структур с параметрами

void initializationContinent(Сontinent continent, int number, int square, char *name, Country countries[]) {
    int i;
    int lenOfName = strlen(name);
    continent.nameOfContinent = (char*)calloc(lenOfName, sizeof(char));
    strcpy(continent.nameOfContinent, name);
    continent.numberOfCountries = number;
    continent.squareOfContinent = square;
    for (i = 0; i < number; i++)
        continent.listOfCountries[i] = countries[i];

}

void initializationCountry(Country country, int budget, int expenses, int income, int profitEnterprises, int number, int population, int square, char* name, Subject subjects[]) {
    int i;
    int lenOfName = strlen(name);
    country.nameOfCountry = (char*)calloc(lenOfName, sizeof(char));
    strcpy(country.nameOfCountry, name);
    country.budgetDeficitOrSurplusOfCountry = budget;
    country.expensesOfCountry = expenses;
    country.incomeOfCountry = income;
    country.netProfitCountryEnterprises = profitEnterprises;
    country.numberOfSubjects = number;
    country.populationOfCountry = population;
    country.squareOfCountry = square;
    for (i = 0; i < number; i++)
        country.listOfSubjects[i] = subjects[i];
}

void initializationSubject(Subject subject, int population, int square, int number, char* name, City cities[]) {
    int i;
    int lenOfName = strlen(name);
    subject.nameOfSubject = (char*)calloc(lenOfName, sizeof(char));
    strcpy(subject.nameOfSubject, name);
    subject.populationOfSubject = population;
    subject.squareOfSubject = square;
    subject.numberOfCities = number;
    for (i = 0; i < number; i++)
        subject.listOfCities[i] = cities[i];
}

void initializationCity(City city, int population, int number, char* name, Enterprise enterprises[]) {
    int i;
    int lenOfName = strlen(name);
    city.nameOfCity = (char*)calloc(lenOfName, sizeof(char));
    strcpy(city.nameOfCity, name);
    city.populationOfCity = population;
    city.numberOfEnterprises = number;
    for (i = 0; i < number; i++)
        city.listOfEnterprises[i] = enterprises[i];
}

void initializationEnterprise(Enterprise enterprise, int profit, int turnover, char* address, char* date, char* industry, char* name) {
    int length;
    length = strlen(name);
    enterprise.nameOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(enterprise.nameOfEnterprise, name);
    length = strlen(industry);
    enterprise.industryOfEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(enterprise.industryOfEnterprise, industry);
    length = strlen(date);
    enterprise.dateOfFoundationEnterprise = (char*)calloc(length, sizeof(char));
    strcpy(enterprise.dateOfFoundationEnterprise, date);
    length = strlen(address);
    strcpy(enterprise.citySubjectCountry, address);
    enterprise.citySubjectCountry = (char*)calloc(length, sizeof(char));
    enterprise.netProfitOfEnterprise = profit;
    enterprise.turnoverPerYear = turnover;
}

// Инициализация всех структур без параметров
void initializationAllStructures(Сontinent continents[]) {
    for (int i = 0; i < MAXCONTINENTS; i++) {
        initializationContinent(continents[i]);
        for (int j = 0; j < MAXCOUNTRIES; j++) {
            initializationCountry(continents[i].listOfCountries[j]);
            for (int k = 0; k < MAXSUBJECTS; k++) {
                initializationSubject(continents[i].listOfCountries[j].listOfSubjects[k]);
                for (int x = 0; x < MAXCITIES; x++) {
                    initializationCity(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x]);
                    for (int z = 0; z < MAXENTERPRISES; z++)
                        initializationEnterprise(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z]);
                }
            }
        }
    }
}

// Ввод из консоли
void inputСontinentFromConsole(Сontinent continent) {
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
    temp = (char*)realloc(continent.nameOfContinent, length * sizeof(char));
    continent.nameOfContinent = temp;
    strcpy(continent.nameOfContinent, name);
    continent.numberOfCountries = number;
    continent.squareOfContinent = square;
}


void inputCountryFromConsole(Country country) {
    char name[LENNAME];
    int number;
    int square;
    int income;
    int profit;
    int expenses;
    int budget;
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
    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(country.nameOfCountry, length * sizeof(char));
    country.nameOfCountry = temp;
    strcpy(country.nameOfCountry, name);
    country.populationOfCountry = population;
    country.numberOfSubjects = number;
    country.squareOfCountry = square;
    country.incomeOfCountry = income;
    country.expensesOfCountry = expenses;
    country.netProfitCountryEnterprises = profit;
    country.budgetDeficitOrSurplusOfCountry = budget;
}

void inputSubjectFromConsole(Subject subject) {
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
    temp = (char*)realloc(subject.nameOfSubject, length * sizeof(char));
    subject.nameOfSubject = temp;
    strcpy(subject.nameOfSubject, name);
    subject.numberOfCities = number;
    subject.squareOfSubject = square;
    subject.populationOfSubject = population;
}


void inputCityFromConsole(City city) {
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
    temp = (char*)realloc(city.nameOfCity, length * sizeof(char));
    city.nameOfCity = temp;
    strcpy(city.nameOfCity, name);
    city.numberOfEnterprises = number;
    city.populationOfCity = population;
}

void inputEnterpriseFromConsole(Enterprise enterprise) {
    char name[LENNAME];
    int turnover;
    int profit;
    char date[15];
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
    while (getchar() != '\n');
    length = strlen(name);
    temp = (char*)realloc(enterprise.nameOfEnterprise, length* sizeof(char));
    enterprise.nameOfEnterprise = temp;
    temp = NULL;
    strcpy(enterprise.nameOfEnterprise, name);
    temp = (char*)realloc(enterprise.citySubjectCountry, LENNAME * 3 * sizeof(char));
    enterprise.citySubjectCountry = temp;
    temp = NULL;
    length = strlen(date);
    temp = (char*)realloc(enterprise.dateOfFoundationEnterprise, length * sizeof(char));
    enterprise.dateOfFoundationEnterprise = temp;
    temp = NULL;
    strcpy(enterprise.dateOfFoundationEnterprise, date);
    length = strlen(industry);
    temp = (char*)realloc(enterprise.industryOfEnterprise, length * sizeof(char));
    enterprise.industryOfEnterprise = temp;
    temp = NULL;
    strcpy(enterprise.industryOfEnterprise, industry);
    enterprise.turnoverPerYear = turnover;
    enterprise.netProfitOfEnterprise = profit;;
}

void inputAllStructures(Сontinent continents[]) {
    int numberOfCountriesEntered = 0;
    int numberOfSubjectsEntered = 0;
    int i, j, k, x, z;
    i = 0;
    if (numberOfContinentsEntered != MAXCONTINENTS) {
        do {
            inputСontinentFromConsole(continents[i]);
            numberOfContinentsEntered++;
            j = 0;
            do {
                inputCountryFromConsole(continents[i].listOfCountries[j]);
                numberOfCountriesEntered++;
                k = 0;
                do {
                    inputSubjectFromConsole(continents[i].listOfCountries[j].listOfSubjects[k]);
                    numberOfSubjectsEntered++;
                    x = 0;
                    do {
                        inputCityFromConsole(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x]);
                        z = 0;
                        do {
                            inputEnterpriseFromConsole(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z]);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].nameOfCountry);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, ", ");
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].listOfSubjects[k].nameOfSubject);
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, ", ");
                            strcat(continents[i].listOfCountries[j].listOfSubjects[k].listOfCities[x].listOfEnterprises[z].citySubjectCountry, continents[i].listOfCountries[j].listOfSubjects[x].listOfCities[x].nameOfCity);
                            puts("Для завершения ввода предприятий нажмите Esc.");
                            puts("Для продолжения любую другую клавишу.\n");
                            k++;
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
                    z++;
                } while ((_getch() != 27) && (numberOfSubjectsEntered != MAXSUBJECTS));
                if (numberOfCountriesEntered == MAXCOUNTRIES)
                    puts("Вы ввели максимальное количество стан для одного континета!");
                else {
                    puts("Для завершения ввода стран нажмите Esc.");
                    puts("Для продолжения любую другую клавишу.\n");
                }
                continents[i].listOfCountries[j].netProfitCountryEnterprises = calculatingProfitsFromEnterprises(continents[i].listOfCountries[j]);
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

void outputContinentToConsole(Сontinent continent, int number) {
    int i;
    printf("* %-5d * %-18s * %-16d * %-18d * ", number + 1, continent.nameOfContinent, continent.numberOfCountries, continent.squareOfContinent);
    printf("%-30s *\n", continent.listOfCountries[0].nameOfCountry);
    i = 1;
    while ((continent.listOfCountries[i].nameOfCountry != NULL) && (i < continent.numberOfCountries)) {
        printf("*       *                    *                  *                    * %-30s *\n", continent.listOfCountries[0].nameOfCountry);
        i++;
    }
    printf("*******************************************************************************************************\n");
}

void outputCountryToConsole(Country country, int number) {
    int i;
    printf("* %-5d * %-18s * %-20d * %-14d * ", number + 1, country.nameOfCountry, country.numberOfSubjects, country.squareOfCountry);
    printf("%-9d * %-19d * %-10d * ", country.populationOfCountry, country.netProfitCountryEnterprises, country.incomeOfCountry);
    printf("%-11d * %-24d *", country.expensesOfCountry, country.budgetDeficitOrSurplusOfCountry);
    printf("%-25s *\n", country.listOfSubjects[0].nameOfSubject);
    i = 1;
    while ((country.listOfSubjects[i].nameOfSubject != NULL) && (i < country.numberOfSubjects)) {
        printf("*       *                    *                      *                *           *                     *            *             *                          * %-25s *\n", country.listOfSubjects[i].nameOfSubject);
        i++;
    }
    printf("******************************************************************************************************************************************************************************************\n");
}

void outputSubjectToConsole(Subject subject, int number) {
    int i;
    printf("* %-5d * %-18s * %-18d * ", number + 1, subject.nameOfSubject, subject.numberOfCities);
    printf("%-16d * %-9d * ", subject.squareOfSubject, subject.populationOfSubject);
    printf("%-28s *\n", subject.listOfCities[0].nameOfCity);
    i = 1;
    while ((subject.listOfCities[i].nameOfCity != NULL) && (i < subject.numberOfCities)) {
        printf("*       *                    *                    *                  *           * %-28s *\n", subject.listOfCities[i].nameOfCity);
    }
    printf("*****************************************************************************************************************\n");

}
void outputCityToConsole(City city, int number) {
    int i;
    printf("* %-5d * %-18s *%-22d * %-9d * ", number + 1, city.nameOfCity, city.numberOfEnterprises, city.populationOfCity);
    printf("%-36s *\n", city.listOfEnterprises[0].nameOfEnterprise);
    i = 1;
    while ((city.listOfEnterprises[i].nameOfEnterprise != NULL) && (i < city.numberOfEnterprises)) {
        printf("*       *                    *                        *           * %-36s *\n", city.listOfEnterprises[i].nameOfEnterprise);
        i++;
    }
    printf("**********************************************************************************************************\n");
}
void outputEnterpriseToConsole(Enterprise enterprise, int number) {
    printf("* %-5d * %-23s * %-47s * ", number + 1, enterprise.nameOfEnterprise, enterprise.citySubjectCountry);
    printf("%-17d * %-13d * ", enterprise.turnoverPerYear, enterprise.netProfitOfEnterprise);
    printf("%-20s * %-14s *\n", enterprise.industryOfEnterprise, enterprise.dateOfFoundationEnterprise);
    printf("*****************************************************************************************************************************************************************\n");
}

// Шапки таблиц

void continentTableHeader() {
    printf("*******************************************************************************************************\n");
    printf("* Номер *     Континент      * Количество стран * Площадь континента *          Список стран          *\n");
    printf("*******************************************************************************************************\n");
}
void countryTableHeader() {
    printf("******************************************************************************************************************************************************************************************\n");
    printf("* Номер *       Страна       * Количество субъектов * Площадь страны * Население * Прибыль предприятий *   Доходы   *   Расходы   * Профицит/дефицит бюджета *      Список субъектов     *\n");
    printf("******************************************************************************************************************************************************************************************\n");
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
    printf("*****************************************************************************************************************************************************************\n");
    printf("* Номер *       Предприятие       *                  Местоположение                 *   Оборот за год   *    Прибыль    *        Отрасль       * Дата основания *\n");
    printf("*****************************************************************************************************************************************************************\n");
}


// Вычисление прибыли предпритий страны

int calculatingProfitsFromEnterprises(Country country) {
    int i, j, k;
    int numberOfProfit = 0;
    i = 0;
    while (country.listOfSubjects[i].nameOfSubject != NULL) {
        j = 0;
        while (country.listOfSubjects[i].listOfCities[j].nameOfCity != NULL) {
            k = 0;
            while (country.listOfSubjects[i].listOfCities[j].listOfEnterprises[k].nameOfEnterprise != NULL) {
                numberOfProfit += country.listOfSubjects[i].listOfCities[j].listOfEnterprises[k].netProfitOfEnterprise;
                k++;
            }
            j++;
        }
        i++;
    }
    return numberOfProfit;
}

//Сравнение характеристик двух стран

void comparisonOfTwoCountries(Country* firstCountry, Country* secondCountry) {
    int percentageOfSquare;
    int percentageOfPopulation;
    int percentageOfProfits;
    int percentageOfIncome;
    int percentageOfExpenses;
    puts("СРАВНЕНИЕ ДВУХ СТРАН");
    countryTableHeader();
    outputCountryToConsole(*firstCountry, 1);
    outputCountryToConsole(*secondCountry, 2);
    puts("\nПроцентное соотношение характеристик стран");
    printf("%s     %s\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry);
    // Площадь
    if (firstCountry->squareOfCountry > secondCountry->squareOfCountry) {
        percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->squareOfCountry, secondCountry->squareOfCountry);
        printf("Площадь страны - %s больше площади страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfSquare);
    }
    else if (firstCountry->squareOfCountry < secondCountry->squareOfCountry) {
        percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->squareOfCountry, firstCountry->squareOfCountry);
        printf("Площадь страны - %s больше площади страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfSquare);
    }
    else
        printf("Площади стран равны\n");
    // Население
    if (firstCountry->populationOfCountry > secondCountry->populationOfCountry) {
        percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->squareOfCountry, secondCountry->squareOfCountry);
        printf("Населeние страны - %s больше населения страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfPopulation);
    }
    else  if (firstCountry->squareOfCountry < secondCountry->squareOfCountry) {
        percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->squareOfCountry, firstCountry->squareOfCountry);
        printf("Населeние страны - %s больше населения страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfPopulation);
    }
    else
        printf("Население стран равно");
    //Прибыль предприятий 
    if (firstCountry->netProfitCountryEnterprises > secondCountry->netProfitCountryEnterprises) {
        percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->netProfitCountryEnterprises, secondCountry->netProfitCountryEnterprises);
        printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfProfits);
    }
    else if (firstCountry->netProfitCountryEnterprises < secondCountry->netProfitCountryEnterprises) {
        percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->netProfitCountryEnterprises, firstCountry->netProfitCountryEnterprises);
        printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfProfits);
    }
    else printf("Прибыли предприятий стран равны\n");
    // Доходы
    if (firstCountry->incomeOfCountry > secondCountry->incomeOfCountry) {
        percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(firstCountry->incomeOfCountry, secondCountry->incomeOfCountry);
        printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", firstCountry->nameOfCountry, secondCountry->nameOfCountry, percentageOfIncome);
    }
    else if (firstCountry->incomeOfCountry < secondCountry->incomeOfCountry) {
        percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->incomeOfCountry, firstCountry->incomeOfCountry);
        printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfIncome);
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
        printf("Расходы страны - %s больше доходов страны - %s на %d %%\n", secondCountry->nameOfCountry, firstCountry->nameOfCountry, percentageOfExpenses);
    }
    else
        printf("Расходы стран равны\n");
}

int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(int a, int b) {
    int result;
    result = (a - b) / b * 100;
    return result;
}