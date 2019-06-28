#include <iostream>
#include <fstream>

using namespace std;

class Spreadsheet {
    protected:
        
    public: 
        void viewSheet(), printSheet(), loadSheet(), functions(), insertFunc(int x, int y, int value), deleteFunc(int x, int y);
        int menu();
        void sumFunc(int x1, int y1, int x2, int y2), searchFunc(int value), sortFunc(int area, int method, int r, int c);
        void mean(int area, int r, int c), min(int area, int r, int c), max(int area, int r, int c);
        string getCommand(string str);
        string command, param1, param2, str, col = "ABCDEFGHIJ";
        int choosenMenu;
        int arr[10][10] = {
            {5, 2, 6, 1, 3, 4, 7, 1, 8, 9},
            {4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {3, 4, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 3, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 9, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 7, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 0, 0, 0, 0, 0, 0, 0, 0}
        };
}sheet;

int Spreadsheet::menu() {
    awal:
    system("clear");
    cout << "YOSSAN'S SPREADSHEET" << endl;
    cout << "1. View Spreadsheet" << endl;
    cout << "2. Print Spreadsheet" << endl;
    cout << "3. Load Spreadsheet" << endl;
    cout << "4. Functions" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose a menu : "; cin >> choosenMenu;
    cout << endl;
    if (choosenMenu == 1) {
        viewSheet();
    } else if (choosenMenu == 2) {
        printSheet();
    } else if (choosenMenu == 3) {
        loadSheet();
    } else if (choosenMenu == 4) {
        cout << "Type your command : "; cin >> str;
        functions();
    } else if (choosenMenu == 5) {
        return 0;
    }
    system( "read -n 1 -s -p \"\nPress any key to continue...\"" );
    goto awal;
}

void Spreadsheet::viewSheet() {
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "\t";
            for (int k = 0; k < 10; k++) {
                cout << col[k] << "  ";
            }
            cout << endl;
            cout << "\t-----------------------------" << endl;
        }
        for (int j = 0; j < 10; j++) {
            if(j == 0) {
                cout << i + 1 << "\t";
            }
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void Spreadsheet::printSheet() {
    string filename;
    cout << "Give your sheet name : ";
    cin >> filename;
    ofstream myfile;
    myfile.open(filename);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            myfile << arr[i][j];
        }
        myfile << endl;
    }
    myfile.close();
}

void Spreadsheet::loadSheet() {
    string filename;
    cout << "Type your file name : ";
    cin >> filename;
    ifstream filein;
    int area = 0;
    filein.open(filename);
    for (string line; getline(filein, line); )
    { 
        for (int i = area; i < area + 1; i++) {
            for (int j = 0; j < 10; j++)
            {
                char a = line[j];
                arr[i][j] = stoi(&a);
            }
            
        }
        area++;
    }
    filein.close();
}

void Spreadsheet::functions() {
    getCommand(str);
    cout << command << endl;
    cout << param1 << endl;
    cout << param2 << endl;
    int dim1, dim2, value;

    if (command == "SET") {
        char temp[1];
        param1.copy(temp, 1, 0);
        param1.erase(param1.begin());
        dim1 = (stoi(param1) - 1);
        dim2 = temp[0] - 65;
        value = stoi(param2);
        insertFunc(dim1, dim2, value);
    } else if (command == "DEL") {
        char temp[1];
        param1.copy(temp, 1, 0);
        param1.erase(param1.begin());
        dim1 = (stoi(param1) - 1);
        dim2 = temp[0] - 65;
        deleteFunc(dim1, dim2);
    } else if (command == "SUM") {
        int dim1First, dim2First, dim1Last, dim2Last;
        char temp1[1], temp2[1];
        param1.copy(temp1, 1, 0);
        param1.erase(param1.begin());
        param2.copy(temp2, 1, 0);
        param2.erase(param2.begin());
        dim1First = (stoi(param1) - 1);
        dim2First = temp1[0] - 65;
        dim1Last = (stoi(param2) - 1);
        dim2Last = temp2[0] - 65;
        sumFunc(dim1First, dim2First, dim1Last, dim2Last);
    } else if (command == "SEARCH") {
        int value = stoi(param1);
        searchFunc(value);
    } else if (command == "SORT") {
        char temp[1];
        param1.copy(temp, 1, 0);
        int area, method, r, c;
        if ((temp[0] - 65) > 9 || (temp[0] - 65) < 0) {
            area = (stoi(param1) - 1);
            r = 0;
            c = 10;
        } else {
            area = temp[0] - 65;
            r = 10;
            c = 0;
        }
        method = stoi(param2);
        sortFunc(area, method, r, c);
    } else if (command == "MEAN") {
        char temp[1];
        param1.copy(temp, 1, 0);
        int area, r, c;
        if ((temp[0] - 65) > 9 || (temp[0] - 65) < 0) {
            area = (stoi(param1) - 1);
            r = 0;
            c = 10;
        } else {
            area = temp[0] - 65;
            r = 10;
            c = 0;
        }
        mean(area, r, c);
    } else if (command == "MIN") {
        char temp[1];
        param1.copy(temp, 1, 0);
        int area, r, c;
        if ((temp[0] - 65) > 9 || (temp[0] - 65) < 0) {
            area = (stoi(param1) - 1);
            r = 0;
            c = 10;
        } else {
            area = temp[0] - 65;
            r = 10;
            c = 0;
        }
        min(area, r, c);
    } else if (command == "MAX") {
        char temp[1];
        param1.copy(temp, 1, 0);
        int area, r, c;
        if ((temp[0] - 65) > 9 || (temp[0] - 65) < 0) {
            area = (stoi(param1) - 1);
            r = 0;
            c = 10;
        } else {
            area = temp[0] - 65;
            r = 10;
            c = 0;
        }
        max(area, r, c);
    }
}

void Spreadsheet::insertFunc(int x, int y, int value) {
    arr[x][y] = value;
}

void Spreadsheet::deleteFunc(int x, int y) {
    arr[x][y] = 0;
}

void Spreadsheet::sumFunc(int x1, int y1, int x2, int y2) {
    int sum = 0;

    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            cout << arr[i][j] << endl;
            sum += arr[i][j];
        }
        
    }
    cout << "The SUM is = " << sum << endl;
}

void Spreadsheet::searchFunc(int value) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (value == arr[i][j]) {
                cout << "[" << col[j] << i + 1 << "]" << " ";
            }
        }
    }
    cout << endl;
}

void Spreadsheet::sortFunc(int area, int method, int r, int c) {
    int temp;
    int sortArr[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sortArr[i][j] = arr[i][j];
        }
        
    }

    if (method == 1 && r > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = area; j < area + 1; j++) {
                temp = sortArr[i][j];
                for (int k = i + 1; k < 10; k++) {
                    if (temp > sortArr[k][j]) {
                        sortArr[i][j] = sortArr[k][j];
                        sortArr[k][j] = temp;
                        temp = sortArr[i][j];
                    }
                }
            }
        }
    } else if (method == 1 && r == 0) {
        cout << "work" << endl;
        for (int i = area; i < area + 1; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                temp = sortArr[i][j];
                for (int k = 0; k < 10; k++)
                {
                    if (temp < sortArr[i][k])
                    {
                        sortArr[i][j] = sortArr[i][k];
                        sortArr[i][k] = temp;
                        temp = sortArr[i][j];
                    }
                }
                
            }
            
        }
    }

    if (method == 0 && r > 0) {
        for (int i = 0; i < 10; i++)
        {
            for (int j = area; j < area + 1; j++)
            {
                temp = sortArr[i][j];
                for (int k = i + 1; k < 10; k++)
                {
                    if (temp < sortArr[k][j]) {
                        sortArr[i][j] = sortArr[k][j];
                        sortArr[k][j] = temp;
                        temp = sortArr[i][j];
                    }
                }
            }
        }
    } else if (method == 0 && r == 0) {
        for (int i = area; i < area + 1; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                temp = sortArr[i][j];
                for (int k = 0; k < 10; k++)
                {
                    if (temp > sortArr[i][k])
                    {
                        sortArr[i][j] = sortArr[i][k];
                        sortArr[i][k] = temp;
                        temp = sortArr[i][j];
                    }
                }
                
            }
            
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "\t";
            for (int k = 0; k < 10; k++) {
                cout << col[k] << "  ";
            }
            cout << endl;
            cout << "\t-----------------------------" << endl;
        }
        for (int j = 0; j < 10; j++) {
            if(j == 0) {
                cout << i + 1 << "\t";
            }
            cout << sortArr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Spreadsheet::mean(int area, int r, int c) {
    int result;
    float mean;
    if (r > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = area; j < area + 1; j++)
            {
                result += arr[i][j];
            }
        }
    } else {
        for (int i = area; i < area + 1; i++) {
            for (int j = 0; j < 10; j++) {
                result += arr[i][j];
            }  
        }
        
    }
    mean = float(result) / float(10);
    cout << "The MEAN of " << param1 << " = " << mean << endl;
}

void Spreadsheet::min(int area, int r, int c) {
    int minimum = 0;
    if (r > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = area; j < area + 1; j++) {
                if (minimum > arr[i][j]) {
                    minimum = arr[i][j];
                }
            }
        }
    } else {
        for (int i = area; i < area + 1; i++) {
            for (int j = 0; j < 10; j++) {
                if (minimum > arr[i][j]) {
                    minimum = arr[i][j];
                }
            }
        }
    }
    cout << "The Minimum value of " << param1 << " = " << minimum << endl;
}

void Spreadsheet::max(int area, int r, int c) {
    int maximum = 0;
    if (r > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = area; j < area + 1; j++) {
                if (maximum < arr[i][j]) {
                    maximum = arr[i][j];
                }
            }
        }
    } else {
        for (int i = area; i < area + 1; i++) {
            for (int j = 0; j < 10; j++) {
                if (maximum < arr[i][j]) {
                    maximum = arr[i][j];
                }
            }
        }
    }
    cout << "The Maximum value of " << param1 << " = " << maximum << endl;
}

string Spreadsheet::getCommand (string str) {
    command = "";
    param1 = "";
    param2 = "";
    for (auto x : str) {
        if (command.length() < str.find('(')) {
            command += x;
        } else if (x != '(' && param1.length() + command.length() + 1 < str.find(',')) {
            if(param1.length() + command.length() > command.length() + 2 || x == ')') { //for 1 paramater
                return " ";
            } else {
                param1 += x;
            }
        } else if (x != '(' && x != ',' && param1.length() + param2.length() + command.length() + 2 < str.find(')')) {
            param2 += x;
        }
    }
    return "";
}

int main () {
    sheet.menu();

    return 0;
}