#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

// I am zhangshuaishuai. I was born on 2000.10.20. My phone number is 18866667777 and you can also reach me by my email: zhangss@mails.tsinghua.edu.cn.
// I am hanmeimei. I was born on 1998-2-3. You can add my WeChat by my mobile number 16677778888, and my email is hmm@gmail.com.
// (?:I am |My name is )(\w+)\..+(\d{4})(?:\.|-)(\d+)(?:\.|-)(\d+)\. .+(\d{11}).+\s(.+@(?:[\w][-\w\d]+\.)+[\w]{2,14})

struct Student {
    string name;
    string y;
    string m;
    string d;
    string phone;
    string email;
} students[500];

bool cmp(const Student& a, const Student& b) {
    string m1, d1, m2, d2;
    if (a.m.length() == 1) m1 = "0" + a.m;
    else m1 = a.m;
    if (a.d.length() == 1) d1 = "0" + a.d;
    else d1 = a.d;
    if (b.m.length() == 1) m2 = "0" + b.m;
    else m2 = b.m;
    if (b.d.length() == 1) d2 = "0" + b.d;
    else d2 = b.d;
    if (a.y != b.y) return a.y < b.y;
    else if (m1 != m2) return m1 < m2;
    else return d1 < d2;
}

int main () {
    int n;
    //string s("I am zhangshuaishuai. I was born on 2000.10.20. My phone number is 18866667777 and you can also reach me by my email: zhangss@mails.tsinghua.edu.cn.");
    regex re_name(R"((?:I am |My name is )(\w+))");
    regex re_bday(R"((\d{4})(?:\.|-)(\d+)(?:\.|-)(\d+))");
    regex re_pnum(R"((\d{11}))");
    regex re_mail(R"([^w](\w[\w\d\.]*@(?:[\w][-\w\d]+\.)+[\w]{2,14}))");
    smatch sm_name;
    smatch sm_bday;
    smatch sm_pnum;
    smatch sm_mail;
    cin >> n;
    string s;
    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        regex_search(s,sm_name,re_name);
        regex_search(s,sm_bday,re_bday);
        regex_search(s,sm_pnum,re_pnum);
        regex_search(s,sm_mail,re_mail);
        students[i].name = sm_name[1];
        students[i].y = sm_bday[1];
        students[i].m = sm_bday[2];
        students[i].d = sm_bday[3];
        students[i].phone = sm_pnum[0];
        students[i].email = sm_mail[1];
    }
    sort(students, students + n, cmp);
    string m, d;
    for (int i = 0; i < n; i++) {
        Student &stu = students[i];
        if (stu.m.length() == 1) m = "0" + stu.m;
        else m = stu.m;
        if (stu.d.length() == 1) d = "0" + stu.d;
        else d = stu.d;
        cout << stu.name 
             << "-" << stu.y << "." << m << "." << d
             << "-" << stu.phone << "-" << stu.email
             << endl;
    }
    // cout << sm.size() << " matches\n";
    // cout << "the matches were:" << endl;
    // for (unsigned i=0; i<sm.size(); ++i) {
    //     cout << sm[i] << endl;
    // }
    //string s1 = sm[0];
    //cout << s1 << endl;
    return 0;
}