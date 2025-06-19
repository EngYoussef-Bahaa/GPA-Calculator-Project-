#include <iostream>
using namespace std;
struct stGPA
{

    short Numofclasses = 0;

    short* hours = nullptr;

    char* Grade = nullptr;

    short* points = nullptr;

    short TotalQP = 0;

    short TotalHours = 0;

    double GPA;

};

stGPA ReadNumberofclasses(stGPA GPA)
{


    cout << "Enter How Many Classes You had finished ? \n";

    cin >> GPA.Numofclasses;






    return GPA;
}

stGPA ReadHours(stGPA GPA)
{
    GPA.hours = new short[GPA.Numofclasses];
    for (short i = 0; i < GPA.Numofclasses; i++)
    {
        cout << "Enter Hours of " << i + 1 << " Class\n";
        cin >> GPA.hours[i];
        GPA.TotalHours += GPA.hours[i];
    }
    return GPA;
}

short CalPoint(char c)
{
    switch (c)
    {
    case 'A':
        return 4;
    case  'B':
        return 3;
    case 'C':
        return 2;
    case 'D':
        return 1;
    case 'F':
        return 0;
    }
    switch (c)
    {
    case 'a':
        return 4;
    case  'b':
        return 3;
    case 'c':
        return 2;
    case 'd':
        return 1;
    case 'f':
        return 0;
    }
    return 0;

}

stGPA ReadGrade(stGPA GPA)
{

    GPA.Grade = new char[GPA.Numofclasses];
    GPA.points = new short[GPA.Numofclasses];
    for (short i = 0; i < GPA.Numofclasses; i++)
    {
        cout << "Enter Grade of " << i + 1 << " Class\n";
        cin >> GPA.Grade[i];
        GPA.points[i] = CalPoint(GPA.Grade[i]);
    }
    return GPA;
}

stGPA CalculateTotalQP(stGPA GPA)
{
    for (short i = 0; i < GPA.Numofclasses; i++)
    {

        GPA.TotalQP += (GPA.hours[i] * GPA.points[i]);
    }
    return GPA;


}

stGPA CalculateGPA(stGPA GPA)
{
    GPA.GPA = (double) GPA.TotalQP/GPA.TotalHours ;
    return GPA;
}

void ScreenResaultGPA(stGPA GPA)
{

    cout << "\t\t**************************************\n\n";

    cout << "\t\t G P A  =  " << GPA.GPA << "\n\n";

    cout << "\t\t**************************************\n\n";


}

void GPACalculator()
{
    stGPA GPA;
    ScreenResaultGPA(CalculateGPA(CalculateTotalQP(ReadGrade(ReadHours(ReadNumberofclasses(GPA))))));
    delete[] GPA.hours;
    delete[] GPA.Grade;
    delete[] GPA.points;
}

int main()
{
    GPACalculator();



    return 0;
}