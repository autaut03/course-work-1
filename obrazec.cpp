#include <iostream>
#include <windows.h>      // Для роботи з консоллю.
#include <conio.h>        // getch()
#include <locale>         // Lenguages.
#include <fstream>        // Files.
#include <iomanip>        // setw(), left
#include <sstream>        // ostringstream
#include <string>         // to_string()
#include <algorithm>
#include <cctype>         // tolower()
#include <string>

using namespace std;

void printc(char, string);
inline void clear();
inline void clear(string);
bool logIn();
int createMenuList(int, const string*, int, string);
void adminMenu();
void questMenu();

template <class T>
string toString(T param) {
    string str = "";
    stringstream ss;
    ss << param;
    getline(ss, str);
    return str;
}

template <class T>
T convStrToInt(char *arg, T x) {
    char *arg1 = arg;
    while(*arg != '\0') {
        if(!isdigit(*arg)) {
            return -1;
        }
        *arg++;
    }
    x = atoi(arg1);
    if (x < 0) x = 0;
    return x;
}

class List {
protected:
    string __listName;
    long int __listSize;
    string *__columnsArr;
    int __columnsSize;
    int *__columnsLen;
    bool *__columnsTypes; //true - int, false - string;
    string __fileName;
    string __columnsFileName;

    void quicSort(bool, string*, long int, long int, const int);

    void checkColumns() {
        int columnsSize = 0;
        ifstream s_file(__columnsFileName.c_str());
        char d;
        while ((d = s_file.get()) != EOF) {
            if (d == '\n')
                columnsSize++;
        }
        s_file.close();
        __columnsSize = columnsSize;

        __columnsArr = new string [__columnsSize];
        __columnsLen = new int [__columnsSize];
        __columnsTypes = new bool [__columnsSize];

        ifstream file(__columnsFileName.c_str());

        string temp = "";
        char c;
        int toSize = 0;
        int count = 0;
        int tmp = 1;

        while((c = file.get()) != EOF) {
            if (c == ';') {
                if (tmp == 1) {
                    __columnsArr[toSize] = temp;
                    temp = "";
                    tmp++;
                } else if (tmp == 2) {
                    __columnsLen[toSize] = convStrToInt(&temp[0], tmp);
                    temp = "";
                    tmp++;
                } else if (tmp == 3) {
                    if (temp == "1") __columnsTypes[toSize] = true;
                    else __columnsTypes[toSize] = false;
                    tmp = 1;
                    temp = "";
                }
            } else if (c == '\n') {
                if ((c = file.get()) == EOF) break;
                else temp += c;
                toSize++;
            } else temp += c;
        }
    }

    void checkList() {

        ifstream s_file(__fileName.c_str());
        int size = 0;
        char a;
        while ((a = s_file.get()) != EOF) {
            if( a == '\n' ) {
                size++;
            }
        }
        s_file.close();
        __listSize = size;

        __list = new string *[__listSize];
        for (int i = 0; i < __listSize; i++) {
            __list[i] = new string [__columnsSize];
        }

        ifstream file(__fileName.c_str(), ios::in); // відкриття файлу для читання
        char c;
        string temp = "";
        int i = 0, j = 0;

        while( (c = file.get()) != EOF ) {
            if (j > __columnsSize) {
                j = 0;
                i++;
                continue;
            }
            if (c == EOF) {
                break;
            } else if (c == ';') {
                __list[i][j] = temp;
                temp = "";
                j++;
            } else if (c == '\n') {
                j = 0;
                i++;
            }else temp += c;
        }
        file.close();
    }

public:
    string **__list;
    List () {  }
    List(string _listName, string _fileName, string _columnsFileName) : __fileName(_fileName), __columnsFileName(_columnsFileName), __listName(_listName) {
        checkColumns();
        checkList();
    }

    void editMember();
    void overwrite();
    void sort(string);
    void searching(string);
    void setColumn();
    void removeColumn();
    void expBilder();

    long int getListSize() {
        return __listSize;
    }

    string getListName() {
        return __listName;
    }

    void createNewMember() {
        unsigned int tmp;
        string lines[__columnsSize];
        clear();
        cout << "Створення нового запису . . .\n" << endl;

        ostringstream ost; // Перевід числа в строку
        for(int i = 0; i < __columnsSize; i++) {
            cout << __columnsArr[i] << ":  ";
            getline(cin, lines[i]);
            if (__columnsTypes[i]) {
                if (lines[i].size() == 0) tmp = 0;
                else if(lines[i].size() > 4) tmp = 9999;
                else {
                    if((convStrToInt(&lines[i][0], i)) == -1) tmp = 0;
                    else tmp = convStrToInt(&lines[i][0], tmp);
                }
                ost.str("");
                ost.clear();
                ost << tmp;              // Бібліотеки sstream i string
                lines[i] = ost.str();
            } else {
                if (lines[i].size() == 0) lines[i] = "(не вказано)";
                else if(lines[i].size() > __columnsLen[i]) lines[i].resize(__columnsLen[i]);
            }
            clear();
            cout << "Створення нового запису . . .\n" << endl;
            for(int j = 0; j <= i; j++) {
                cout << __columnsArr[j] << ":  ";
                cout << lines[j] << endl;
            }
        }

        cout << "\n\n(Запис може бути редагований пiзнiше!)\n";
        char c;
        do {
            cout << "Зберегти? (y/n) --> ";
            cin >> c;
            cin.ignore(100, '\n'); // Очищує  потік вводу для передбачення некоректного вводу наступної ітерації.
            if(c == 'n') {
                cout << "\nЗмiни не збережено!" << endl;
                return;
            }
        } while (c != 'y');

        __listSize++;
        string **newList = new string *[__listSize];
        for (int i = 0; i < __listSize; i++) {
            newList[i] = new string [__columnsSize];
            if (i == __listSize - 1) {
                for (int j = 0; j < __columnsSize; j++) {
                    newList[i][j] = lines[j];
                }
            } else {
                for (int j = 0; j < __columnsSize; j++) {
                    newList[i][j] = __list[i][j];
                }
            }
        }

        __list = new string *[__listSize];
        for (int i = 0; i < __listSize; i++) {
            __list[i] = new string [__columnsSize];
            for (int j = 0; j < __columnsSize; j++) {
                __list[i][j] = newList[i][j];
            }
        }

        for (int i = 0; i < __listSize; i++) {
            delete []newList[i];
        }
        delete []newList;

        printc('g', "\nНовий запис створено!\n");
    }

    void getList() {
        if (__listSize == 0) {
            cout << "База даних не мiстить жодного елемента!" << endl;
            return;
        }

        int numWeight = 3;

        cout << "||";
        for(int x = 0; x < numWeight; x++) {
            cout << '=';
        }

        for(int index1 = 0; index1 < __columnsSize; index1++) {
            cout << "||";
            for(int x = 0; x < __columnsLen[index1]; x++) {
                cout << '=';
            }
        }

        cout << "||\n";
        cout << "||" << setw( numWeight ) << left << "№";
        for(int k = 0; k < __columnsSize; k++) {
            cout << "||" << setw( __columnsLen[k] ) << left << __columnsArr[k];
        }
        cout << "||\n";

        cout << "||";
        for(int x = 0; x < numWeight; x++) {
            cout << '=';
        }
        for(int index1 = 0; index1 < __columnsSize; index1++) {
            cout << "||";
            for(int x = 0; x < __columnsLen[index1]; x++) {
                cout << '=';
            }
        }
        cout << "||\n";


        int num = 1;
        cout << "||" << setw( numWeight ) << left << num;
        num++;
        for (int i = 0; i < __listSize; i++) {
            for (int j = 0; j < __columnsSize; j++) {
                cout << "||" << setw( __columnsLen[j] ) << left << __list[i][j]; // виводить слово
            }
            cout << "||";
            if ( i != ( __listSize - 1 ) ) {
                cout << "\n||" << setw( numWeight ) << left << num; // виводить порядковий номер
                num++;
            }
        }
    }

    void clearList() {
        cout << "Очищення списку\n" << endl;
        if (__listSize == 0) {
            cout << "\nБазy даних не знайдено!" << endl;
            return;
        }

        char a;
        do {
            cout << "Ви впевненi? (y/n) --> ";
            cin >> a;
            cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
            if(a == 'n') {
                cout << "\nБаза даних НЕ очищена!\n";
                return;
            }
            cout << endl;
        } while (a != 'y');

        for (int i = 0; i < __listSize; i++) {
            delete []__list[i];
        }
        __listSize = 0;

        printc('g', "Очищення бази даних успiшно завершено!");
        getch();
    }

    void removeMember() {
        string arg;
        cout << "Видалення учасника\n\nВведіть номер учасника:  ";
        cin >> arg;

        long int count = convStrToInt(&arg[0], count);

        if (__listSize == 0) {
            cout << "Базу даних не знайдено!" << endl;
        } else if (count < 0) {
            cout << "Некоректний ввiд!" << endl;
            return;
        } else if (count > __listSize || count == 0) {
            cout << "Запису пiд номером " << count << " не iснує!" << endl;
            return;
        }

        cout << endl;
        char a;
        do {
            cout << "Видалити учасника під номером " << count << " ? (y/n) --> ";
            cin >> a;
            cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
            if(a == 'n') {
                cout << "\nЗмiни не збережено!" << endl;
                return;
            }
        } while (a != 'y');

        __listSize--;

        string **newList = new string *[__listSize];
        for (int i = 0; i < __listSize; i++) {
            newList[i] = new string [__columnsSize];
            if (i < (count - 1)) {
                for (int j = 0; j < __columnsSize; j++) {
                    newList[i][j] = __list[i][j];
                }
            } else if (i >= (count - 1)) {
                for (int j = 0; j < __columnsSize; j++) {
                    newList[i][j] = __list[i+1][j];
                }
            }
        }

        __list = new string *[__listSize];
        for (int i = 0; i < __listSize; i++) {
            __list[i] = new string [__columnsSize];
            for (int j = 0; j < __columnsSize; j++) {
                __list[i][j] = newList[i][j];
            }
        }

        for (int i = 0; i < __listSize; i++) {
            delete []newList[i];
        }
        delete []newList;

        printc('g', "\nВидалення успiшно завершено!\n");
    }

    ~List() {
        for (int i = 0; i < __listSize; i++) {
            delete []__list[i];
        }
        delete []__list;
        delete []__columnsArr;
        delete []__columnsLen;
        delete []__columnsTypes;
    }
};

class MainList : public List {
public:
    MainList() : List("Повний список учасникiв \"Zahidfest\"", "mainDB.txt", "mainColumns.txt") {   }
};

class ClientList : public List {
public:
    ClientList() : List("Cписок замовлень квиткiв", "clientsDB.txt", "clientsColumns.txt") {   }
    void createOrder();
};

int main(int argc, char** argv) {

    system("color 0F");
    HWND hwnd = GetForegroundWindow();
    MoveWindow(hwnd, -8, -31, 1382, 743, TRUE);
    setlocale(LC_ALL, "UKRAINIAN");

    string menuArray[] = {"Гiсть", "Адмiнiстратор Zahidfest", "Завершити роботу"};
    int count = 1;

    while (true) {
        clear("Вхiд:");
        count = createMenuList(count, menuArray , sizeof(menuArray) / sizeof(string), "Вхiд:");
        switch(count) {
            case 1:
                clear();
                cout << "\nВи ввiйшли як \"Гiсть\"" << endl;
                questMenu();
                continue;
            case 2:
                if (logIn()) {
                    cout << "\nВхiд як \"Адмiнiстратор Zahidfest\"" << endl;
                    adminMenu();
                    continue;
                }
            case 3:
                clear();
                cout << "\nВихiд . . ." << endl;
                return 0;
            default:
                continue;
        }
    }
    return 0;
}

void adminMenu() {
    MainList mainList;
    ClientList clientsList;
    int switchCounter = 1;
    while (true) {
        clear("Адмiнiстратор > Головне меню");
        string menuArray[] = { "Переглянути список учасникiв", "Пошук учасника", "Додати учасника", "Редагувати iнформацiю про учасника", "Видалити учасника", "Очистити список учасникiв", "Переглянути список замовлень", "Додати поле", "Видалити останнє поле", "Повернутись у попереднє меню" };
        switchCounter = createMenuList(switchCounter, menuArray, (sizeof(menuArray) / sizeof(string)), "Адмiнiстратор > Головне меню");
        clear();
        switch(switchCounter) {
            case 1:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.sort("Адмiнiстратор > Головне меню > Вивiд");
                getch();
                continue;
            case 2:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.searching("Адмiнiстратор > Головне меню > Пошук");
                getch();
                continue;
            case 3:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.createNewMember();
                getch();
                continue;
            case 5:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.removeMember();
                getch();
                continue;
            case 4:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.editMember();
                getch();
                continue;
            case 6:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.clearList();
                getch();
                continue;
            case 7:
                cout << "\t\t\t" << clientsList.getListName() << '\n' << endl;
                clientsList.sort("Адмiнiстратор > Головне меню > Вивiд");
                getch();
                continue;
            case 8:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.setColumn();
                getch();
                continue;
            case 9:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.removeColumn();
                getch();
                continue;
            case 10:
                char c;
                do {
                    cout << "Вийти з облiкового запису? (y/n) --> ";
                    cin >> c;
                    cin.ignore(100, '\n'); // Очищує  потік вводу для передбачення некоректного вводу наступної ітерації.
                    if(c == 'y') {
                        mainList.overwrite();
                        clientsList.overwrite();
                        return;
                    }
                    clear();
                } while (c != 'n');
                continue;
            default:
                continue;
        }
    }
}

void questMenu() {
    MainList mainList;
    ClientList clientsList;
    int switchCounter = 1;
    while (true) {
        clear("Гiсть > Головне меню");
        string menuArray[] = {"Переглянути список учасникiв", "Пошук учасника", "Замовити квиток", "Повернутись у попереднє меню"};
        switchCounter = createMenuList(switchCounter, menuArray, (sizeof(menuArray) / sizeof(string)), "Гiсть > Головне меню");
        clear();
        switch(switchCounter){
            case 1:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.sort("Адмiнiстратор > Головне меню > Вивiд");
                getch();
                continue;
            case 2:
                cout << "\t\t\t" << mainList.getListName() << '\n' << endl;
                mainList.searching("Адмiнiстратор > Головне меню > Пошук");
                getch();
                continue;
            case 3:
                cout << "\t\t\t" << clientsList.getListName() << '\n' << endl;
                clientsList.createOrder();
                getch();
                continue;
            case 4:
                clientsList.overwrite();
                return;
            default:
                continue;
        }
    }
}

bool logIn() {
    string log = "max", pass = "admin", wlog, wpass;
    clear();
    while (true) {

        cout << "\nВхiд в систему як Адмiнiстратор\n";
        cout << "Ведiть логiн:  ";
        getline(cin, wlog);
        cout << "Ведiть пароль:  ";
        getline(cin, wpass);

        clear();
        if(wpass == pass && wlog == log) {
            return true;
        } else {
            printc('r', "|!| Не правильно введений логiн або пароль!\n");
        }

    }
}

int createMenuList(int p, const string *arr, int size, string w) {
    int button = 0, z;
    if(p < 1 || p - 1 >= size) z = 0;
    else z = p - 1;

    while (true) {
        if (w == "") clear();
        else clear(w);
        if(z < 0) z = size - 1;
        else if(z > size - 1) z = 0;
        for (int i = 0; i < size; i++) {
            if (i == z) {
                printc('p', "--> ");
            }
            cout << arr[i] <<endl;
        }
        button = getch();
        if (button == 72) z--;
        else if (button == 80) z++;
        else if (button == 13) {
            return z + 1;
        } else if (button == 32) {
            return -1;
        }
    }
}

inline void clear() {
    system("cls");
    printc('g', "\t\t\tФестиваль \"Zahidfest\"!\n\n");
}

inline void clear(string w) {
    system("cls");
    printc('g', "\t\t\tФестиваль \"Zahidfest\"!\n\n");
    printc('y', w + "\n\n");
}

void printc(char c, string s) {
    short int color;
    short int defCol = 15; // white

    switch(c) {
        case 'p': // purple
            color = 13;
            break;
        case 'g': // green
            color = 10; //2;
            break;
        case 'b': // blue
            color = 11;
            break;
        case 'r': // red
            color = 12; //4;
            break;
        case 'y': // yellow
            color = 14;
            break;
        case 'w': // white
            color = 15;
            break;
        case 'a': // default white
            color = 7;
            break;
        default:
            color = defCol;
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | color));
    cout << s;
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | defCol));
}

void List::editMember() {
    cout << "Редагування iнформацiї про учасника\n\nВведiть номер учасника:  ";
    string arg;
    cin >> arg;
    cin.ignore(100, '\n');
    int count = convStrToInt(&arg[0], count);

    if (__listSize <= 0) {
        cout << "Базу даних не знайдено!" << endl;
        getch();
        return;
    } else if (count < 0) {
        cout << "Некоректний ввiд!" << endl;
        getch();
        return;
    } else if (count > __listSize || count == 0) {
        cout << "Запису пiд номером " << count << " не iснує!" << endl;
        getch();
        return;
    }
    clear();
    cout << endl;

    string toEditArr[__columnsSize];
    for(int i = 0; i < __columnsSize; i++) {
        toEditArr[i] = __list[count - 1][i];
    }

    string menuArr[__columnsSize + 1];
    for (int i = 0; i < __columnsSize; i++) {
        menuArr[i] = __columnsArr[i] + ":  " + toEditArr[i];
    }
    menuArr[__columnsSize] = "Завершити редагування";

    ostringstream ost; // Перевід числа в строку
    unsigned long int conv;
    int z = 1;
    while(true) {
        clear();
        z = createMenuList(z, menuArr, (sizeof(menuArr) / sizeof(string)), "");
        if(z == __columnsSize + 1) break;
        z--;

        cout << "\n" << __columnsArr[z] << ":  ";
        getline(cin, toEditArr[z]);
        if (toEditArr[z].size() == 0) {
            toEditArr[z] = "(не вказано)";
        } else if (toEditArr[z].size() > __columnsLen[z]) toEditArr[z].resize(__columnsLen[z]);
        if (__columnsTypes[z]) {
            if (convStrToInt(&toEditArr[z][0], conv) == -1) conv = 0;
            else conv = convStrToInt(&toEditArr[z][0], conv);
            ost.str("");
            ost.clear();
            ost << conv;              // Бібліотеки sstream i string
            toEditArr[z] = ost.str();
        }
        menuArr[z] = __columnsArr[z] + ":  " + toEditArr[z];
    }

    cout << endl;
    char a;
    do {
        cout << "Зберегти змiни? (y/n) --> ";
        cin >> a;
        cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
        if(a == 'n' || a == 'N') {
            cout << "\nЗмiни не збережено!\n";
            getch();
            return;
        }
    } while (a != 'y');

    for (int i = 0; i < __columnsSize; i++) {
        __list[count][i] = toEditArr[i];
    }

    printc('g', "\nРедагування успiшно завершено!\n");
    getch();
}

void List::overwrite() {
    ofstream file(__fileName.c_str(), ios::trunc | ios::out);

    for(int i = 0; i < __listSize;  i++) {
        for(int j = 0; j < __columnsSize; j++) {
            file << __list[i][j] << ';';
        }
        file << '\n';
    }

    file.close();
}

void List::sort(string headerString) {
    if (__listSize <= 0) {
        cout << "Базу даних не знайдено!" << endl;
        getch();
        return;
    }

    string tempArr[__listSize][__columnsSize];
    for (int i = 0; i < __listSize; i++) {
        for (int j = 0; j < __columnsSize; j++) {
            tempArr[i][j] = __list[i][j];
        }
    }

    string menuArray[__columnsSize + 2];
    for(int i = 0; i < __columnsSize; i++) {
        menuArray[i + 1] = "Сортувати за елементом \"" + __columnsArr[i] + "\"";
    }
    menuArray[0] = "Переглянути невiдсортований список";
    menuArray[(sizeof(menuArray) / sizeof(string)) - 1] = "Повернутись";

    int z = 1, z1 = z, button = 0;

    while (z != sizeof(menuArray) / sizeof(string) ) {
        clear(headerString);
        z = createMenuList(z1, menuArray, sizeof(menuArray) / sizeof(string), headerString);
        z1 = z;
        z--;
        if (z == (sizeof(menuArray) / sizeof(string)) - 1) break;
        else if (z == 0) {
            for (int i = 0; i < __listSize; i++) {
                for (int j = 0; j < __columnsSize; j++) {
                    __list[i][j] = tempArr[i][j];
                }
            }
            clear(headerString + menuArray[z]);
            cout << "(Закiнчити - Enter)" << endl;
            getList();
            getch();
            continue;
        }
        z--;
        string arr[__listSize];
        for (int i = 0; i < __listSize; i++) {
            arr[i] = __list[i][z];
        }
        if (__columnsTypes[z]) {
            for(int i = 0; i < __listSize; i++) {
                arr[i] = "";
                for (int j = 0; j < (__columnsLen[z] - __list[i][z].size()); j++) {
                    arr[i] += '0';
                }
                arr[i] += __list[i][z];
            }
        } else if (!__columnsTypes[z]) {
            for (int i = 0; i < __listSize; i++) {
                transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::tolower);
            }
        }
        bool c = true;
        do {
            clear(headerString + menuArray[z + 1]);
            quicSort(c, arr, 0, __listSize - 1, z);
            cout << "(Сотрувати по зростанню/спаданню - стрiлками ВВЕРХ та ВНИЗ, закiнчити - Enter)" << endl;
            getList();
            button = getch();
            if (button == 72 || button == 80) c = !c;
        } while (button != 13);
    }

    cout << endl;
    char a;
    do {
        cout << "Зберегти вiдсортований список? (y/n) --> ";
        cin >> a;
        cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
        if(a == 'n' || a == 'N') {
            for (int i = 0; i < __listSize; i++) {
                for (int j = 0; j < __columnsSize; j++) {
                    __list[i][j] = tempArr[i][j];
                }
            }
            cout << "\nЗмiни не збережено!\n";
            getch();
            return;
        }
    } while (a != 'y');

    printc('g', "Змiни збережено!");
    getch();
}

void List::quicSort(bool c, string* arr, long int left, long int right, const int z) {
    long i = left, j = right;
    string p, temp;

    p = arr[(i+j) / 2];

    while (i <= j) {

        if(c) {
            while ( arr[i] < p && i <= right) i++;
            while ( arr[j] > p && j >= left) j--;
        } else {
            while ( arr[i] > p && i <= right) i++;
            while ( arr[j] < p && j >= left) j--;
        }

        if( i <= j ) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            for(int k = 0; k < __columnsSize; k++) {
                temp = __list[i][k];
                __list[i][k] = __list[j][k];
                __list[j][k] = temp;
            }
            i++;
            j--;
        }
    }
    if( j > left ) quicSort(c, arr, left, j, z);
    if( i < right ) quicSort(c, arr, i, right, z);
}

void ClientList::createOrder() {
    MainList mainList;
    unsigned long int tmp;
    string lines[__columnsSize];
    int sumPos = (sizeof(lines) / sizeof(string)) - 1;
    int groupsPos = (sizeof(lines) / sizeof(string)) - 2;
    ostringstream ost;
    clear("Гiсть > Головне меню > Замовлення");
    cout << "Створення нового замовлення . . .\n" << endl;
    for(int i = 0; i < groupsPos; i++) {
        cout << __columnsArr[i] << ":  ";
        getline(cin, lines[i]);
        if (lines[i].size() == 0) lines[i] = "(не вказано)";
        else if(lines[i].size() > __columnsLen[i]) lines[i].resize(__columnsLen[i]);
        if (__columnsTypes[i]) {
            if((convStrToInt(&lines[i][0], i)) == -1) tmp = 0;
            else tmp = convStrToInt(&lines[i][0], tmp);
            ost.str("");
            ost.clear();
            ost << tmp;              // Бібліотеки sstream i string
            lines[i] = ost.str();
        }
        clear("Гiсть > Головне меню > Замовлення");
        cout << "Створення нового замовлення . . .\n" << endl;
        for(int j = 0; j <= i; j++) {
            cout << __columnsArr[j] << ":  ";
            cout << lines[j] << endl;
        }
    }

    string menuArr[mainList.getListSize()];
    for(int i = 0; i < mainList.getListSize(); i++) {
        menuArr[i] = mainList.__list[i][0];
    }
    int ch = 0;
    int sum = 0;
    string groups = "";
    lines[groupsPos] = "";
    lines[sumPos] = "0";
    do {
        ch = createMenuList(++ch, menuArr, (sizeof(menuArr) / sizeof(string)), "Гiсть > Головне меню > Замовлення > Вибiр групи\n(Закiнчити - клавiша \"Пробiл\")\nВибранi групи:  " + groups);
        if (ch == -1) {
            break;
        }
        ch--;
        groups += mainList.__list[ch][0] + '|';
        sum += convStrToInt(&(mainList.__list[ch][2])[0], sum);
    } while (true);
    if (groups.size() > 50) {
        groups.resize(__columnsLen[groupsPos] - 3);
        groups += "...";
    }
    lines[sumPos] = toString(sum);
    lines[groupsPos] = groups;
    clear("Гiсть > Головне меню > Замовлення");
    for(int j = 0; j < __columnsSize; j++) {
        cout << __columnsArr[j] << ":  ";
        cout << lines[j] << endl;
    }
    cout << "\n\n(Запис HE може бути редагований пiзнiше!)\n";
    char c;
    cout << "LOOOOL" << endl;
    do {
        cout << "Зберегти? (y/n) --> ";
        cin >> c;
        cin.ignore(100, '\n'); // Очищує  потік вводу для передбачення некоректного вводу наступної ітерації.
        if(c == 'n') {
            cout << "\nЗмiни не збережено!" << endl;
            return;
        }
    } while (c != 'y');

    __listSize++;
    string **newList = new string *[__listSize];
    for (int i = 0; i < __listSize; i++) {
        newList[i] = new string [__columnsSize];
        if (i == __listSize - 1) {
            for (int j = 0; j < __columnsSize; j++) {
                newList[i][j] = lines[j];
            }
        } else {
            for (int j = 0; j < __columnsSize; j++) {
                newList[i][j] = __list[i][j];
            }
        }
    }

    __list = new string *[__listSize];
    for (int i = 0; i < __listSize; i++) {
        __list[i] = new string [__columnsSize];
        for (int j = 0; j < __columnsSize; j++) {
            __list[i][j] = newList[i][j];
        }
    }

    for (int i = 0; i < __listSize; i++) {
        delete []newList[i];
    }
    delete []newList;
    printc('g', "\nНовий запис створено!\n");
}

void List::searching(string headerString) {
    if (__listSize <= 0) {
        cout << "Базу даних не знайдено!" << endl;
        getch();
        return;
    }

    string menuArr[__columnsSize], searchArr[__listSize], word;
    int count = -1;

    for (int i = 0; i < __columnsSize; i++) {
        menuArr[i] = "Пошук за \"" + __columnsArr[i] + "\"";
    }

    int z = createMenuList(-1, menuArr, sizeof(menuArr) / sizeof(string), headerString);
    z--;
    for (int i = 0; i < __listSize; i++) {
        searchArr[i] = __list[i][z];
    }

    clear(headerString);
    cout << "\nПошук:  ";
    getline(cin, word);
    cout << endl;
    for (int i = 0; i < __listSize; i++) {
        if (searchArr[i] == word) {
            count = i;
            break;
        }
    }

    if(count == -1) {
        cout << "Запис не знайдено!" << endl;
        return;
    } else {
        for (int i = 0; i < __columnsSize; i++) {
            cout << __columnsArr[i] << ":  " << __list[count][i] << endl;
        }
    }

}

void List::setColumn() {
    if (__listSize <= 0) {
        cout << "Базу даних не знайдено!" << endl;
        getch();
        return;
    }

    string name = "Column";
    int colType = 0, colLen;

    cout << "Введiть назву поля(не бiльше 30 символiв):  ";
    getline(cin, name);
    cout << "Введiть тип даних поля(якщо чисельний - 1, якщо текстовий - 0):  ";
    cin >> colType;
    cout << "Введiть ширину колонки поля(не менше назви, не бiльше 30):  ";
    colLen = name.length();
    cin >> colLen;

    if (name.length() > 30) {
        name.resize(30);
    }
    if (colType != 1 && colType != 0) {
        colType = 0;
    }
    if (colLen < name.length()) {
        colLen = name.length();
    } else if (colLen > 30) {
        colLen = 30;
    }

    cout << "\n\n";
    cout << "Назва поля:  " << name << endl;
    cout << "Тип поля:  ";
    if (colType == 1) {
        cout << "Чисельний";
    } else if (colType == 0) {
        cout << "Текстовий";
    }
    cout << endl;
    cout << "Ширина поля:  " << colLen << endl;

    cout << endl;
    char a;
    do {
        cout << "Зберегти нове поле? (y/n) --> ";
        cin >> a;
        cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
        if(a == 'n' || a == 'N') {
            cout << "\nЗмiни не збережено!\n";
            return;
        }
    } while (a != 'y');

    ofstream file(__columnsFileName.c_str(), ios::out | ios::app);
    file << name << ';' << colLen << ';' << colType << ';' << endl;
    file.close();

    __columnsSize++;

    string tempColArr[__columnsSize - 1];
    int tempColLen[__columnsSize - 1];
    bool tempColTypes[__columnsSize - 1];

    for (int i = 0; i < __columnsSize - 1; i++) {
        tempColArr[i] = __columnsArr[i];
        tempColLen[i] = __columnsLen[i];
        tempColTypes[i] = __columnsTypes[i];
    }

    __columnsArr = new string [__columnsSize];
    __columnsLen = new int [__columnsSize];
    __columnsTypes = new bool [__columnsSize];

    for (int i = 0; i < __columnsSize - 1; i++) {
        __columnsArr[i] = tempColArr[i];
        __columnsLen[i] = tempColLen[i];
        __columnsTypes[i] = tempColTypes[i];
    }

    __columnsArr[__columnsSize - 1] = name;
    __columnsLen[__columnsSize - 1] = colLen;
    __columnsTypes[__columnsSize - 1] = colType;

    string **newList = new string *[__listSize];
    for (int i = 0; i < __listSize; i++) {
        newList[i] = new string [__columnsSize - 1];
        for (int j = 0; j < __columnsSize - 1; j++) {
            newList[i][j] = __list[i][j];
        }
    }

    __list = new string *[__listSize];
    for (int i = 0; i < __listSize; i++) {
        __list[i] = new string [__columnsSize];
        for (int j = 0; j < __columnsSize; j++) {
            if (j == __columnsSize - 1) {
                __list[i][j] = "";
                continue;
            }
            __list[i][j] = newList[i][j];
        }
    }

    for (int i = 0; i < __listSize; i++) {
        delete []newList[i];
    }
    delete []newList;

    printc('g', "Поле збережено!");
}

void List::removeColumn() {
    if (__listSize <= 0) {
        cout << "Базу даних не знайдено!" << endl;
        getch();
        return;
    }

    char a;
    do {
        printc('r', "|!| Iнформацiю останнього поля буде видалено! |!|\n");
        cout << "Видалити останнє поле? (y/n) --> ";
        cin >> a;
        cin.ignore(100, '\n'); // Очищує потік вводу для передбачення некоректного вводу наступної ітерації.
        if(a == 'n' || a == 'N') {
            cout << "\nЗмiни не збережено!\n";
            return;
        }
    } while (a != 'y');

    __columnsSize--;

    string tempColArr[__columnsSize];
    int tempColLen[__columnsSize];
    bool tempColTypes[__columnsSize];

    for (int i = 0; i < __columnsSize; i++) {
        tempColArr[i] = __columnsArr[i];
        tempColLen[i] = __columnsLen[i];
        tempColTypes[i] = __columnsTypes[i];
    }

    __columnsArr = new string [__columnsSize];
    __columnsLen = new int [__columnsSize];
    __columnsTypes = new bool [__columnsSize];

    for (int i = 0; i < __columnsSize; i++) {
        __columnsArr[i] = tempColArr[i];
        __columnsLen[i] = tempColLen[i];
        __columnsTypes[i] = tempColTypes[i];
    }

    string newList[__listSize][__columnsSize];
    for (int i = 0; i < __listSize; i++) {
        for (int j = 0; j < __columnsSize; j++) {
            newList[i][j] = __list[i][j];
        }
    }

    __list = new string *[__listSize];
    for (int i = 0; i < __listSize; i++) {
        __list[i] = new string [__columnsSize];
        for (int j = 0; j < __columnsSize; j++) {
            __list[i][j] = newList[i][j];
        }
    }

    printc('g', "Поле видалено!");
}