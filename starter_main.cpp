
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
//add given from specification section
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
//implementing through size v how much you can fill of list don't want overfill

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if (size>=capacity){
        throw "List is full";
    }
    //memory alloc
    names[size] = new char[strlen(name)+1];
    strcpy(names[size], name);
    gpas[size]=gpa;
    size++;
}
// TODO: implement updateGPA
//use pointer

void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr){
        *gpaPtr = newGpa;
    }
}

// TODO: implement printStudent
// use method from class std::cout

void printStudent(const char* name, const double& gpa) {
    std::cout <<"Name: " << name <<", GPA: " <<gpa<<std::endl;
}

// TODO: implement averageGPA

double averageGPA(const double gpas[], int size){
    if (size = 0){
        throw "No students in list";
    }
    double total = 0.0;
    for (int i =0; i<size; i++){
        total +=gpas[i];
    }
    return total/size;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                char studentName[100];
                double studentGPA;

                std::cout <<"Enter the Student Name: ";
                std::cin>>studentName;
                std::cout <<"Enter the GPA: ";
                std::cin >> studentGPA;

                try{
                    addStudent(studentName, studentGPA, names, gpas, size, capacity);
                    std::cout<<"Student added"<<std::endl;
                } catch(const char* msg){
                    std::cout<<msg<<std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic

                if (size=0){
                    std::cout<<"No students"<<std::endl;
                    break;
                }
                int idx;
                std::cout<<"Enter student index(0-"<<size-1<<")";
                std::cin>>idx;

                if (idx<0 || idx>=size){
                    std::cout <<"Invalid index"<<std::endl;
                } else{
                    double newGPA;
                    std::cout<<"Enter the new GPA: ";
                    std::cin>>newGPA;
                    updateGPA(&gpas[idx], newGPA);
                    std::cout<<"Updated GPA"<<std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic

                if (size=0){
                    std::cout<<"No students"<<std::endl;
                } else{
                    for(int i=0; i<size;i++){
                        std::cout<<i<<". ";
                        printStudent(names[i], gpas[i]);
                    }
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try{
                    double avg = averageGPA(gpas, size);
                    std::cout<<"Average GPA: "<<avg<<std::endl;
                    std::cout<<"Rounded: " <<static_cast<int>(avg)<<std::endl;
                } catch(const char* msg){
                    std::cout<<msg<<std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i=0; i<size; i++){
        delete[] names[i];
    }

    return 0;
}
