#include <bits/stdc++.h>
using namespace std;

struct Student{
    string lastname, firstname;
    long long points = 0;
    long long credits = 0;
};

int get_point(string mark){
    if (mark == "A+") return 16;
    if (mark == "A") return 15;
    if (mark == "B+") return 14;
    if (mark == "B") return 12;
    if (mark == "C+") return 10;
    if (mark == "C") return 8;
    if (mark == "D+") return 6;
    if (mark == "D") return 4;
    return 0;
}

bool less_student(Student a, Student b){
    long long x = a.points * b.credits;
    long long y = b.points * a.credits;

    if(x != y){
        return x < y;
    }

    if(a.lastname != b.lastname){
        return a.lastname < b.lastname;
    }

    return a.firstname < b.firstname;
}

void quick_sort(int l, int r, vector<Student> &a){
    Student p = a[(l + r) / 2];
    int i = l;
    int j = r;
    while(i <= j){
        while(less_student(a[i], p)){
            i++;
        }
        while(less_student(p, a[j])){
            j--;
        }

        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        quick_sort(l, j, a);
    }
    if(i < r){
        quick_sort(i, r, a);
    }

}



int main(){
    int n;
    cin >> n;
    vector<Student> a(n);
    for(int i = 0; i < n; i++){
        int subjects;
        cin >> a[i].lastname >> a[i].firstname >> subjects;
        for(int j = 0; j < subjects; j++){
            string mark;
            long long credit;
            cin >> mark >> credit;
            a[i].points += get_point(mark) * credit;
            a[i].credits += credit;
        }
    }

    quick_sort(0, n-1, a);
    cout << fixed << setprecision(3);
    for(int i = 0;i < n; i++){
        double gpa = (double)a[i].points / (4.0 * a[i].credits);
        cout << a[i].lastname << " " << a[i].firstname << " " << gpa << '\n';
    }
    return 0;
}