#include<iostream>
#include<string>
#include <vector>

using namespace std;

class student{
private:
    int stu_ID;
    std::string name;
  std::string Email;
   std::vector<course>enrolled_course;

 public:
 student(int stu_ID,std::string name,std::string Email){
    this->stu_ID=stu_ID;
    this->name=name;
    this->Email=Email;
    this->enrolled_course=new vector<>();
 }
 
};
class course{
private:
std::string course_code;
std::string tittle;
course();
int maxCapacity;
std::vector<Student*> students;
public:
course(std::string cousre_code,std::string tittle,std::string instructor,int maxCapacity){
    this->course_code=course_code;
    this->tittle=tittle;
    this->maxCapacity=maxCapacity;
    this->enrolled_students=new vector<>();
}
bool add_student(Student* student) {
        if (students.size() < max_capacity) {
            students.push_back(student);
            return true;
        }
        return false;
    } //function to add new student يعمل فحص ازا ما وصلنا للماكس كاباسيتي يعمل بوش وازا وصلنا للماكس يرجع فولس 

    bool drop_student(Student* student) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == student) {
                students.erase(students.begin() + i);
                return true;
            }
        }
        return false;
    }// بدي الف على كل اللليست للطلاب وفي حال وصلت للطالب يلي بدي اقيمه بعمل على تقصير المسافة محل ما وصلت 
    };
class university{
    private:
     std::vector<student*> students;
     std::vector<course*> courses;
     public:
     university(){
        this.students=new list<>();
        this.courses=new list<>();

     }
     void add_student(student* s){
         students.push_back(student);
    }

     
     void add_course(course* c){
        courses.push_back(course);
    }
    bool enroll_student(Student* student, Course* course) {
        if (std::find(courses.begin(), courses.end(), course) != courses.end() && std::find(students.begin(), students.end(), student) != students.end()) {
            return course->add_student(student);
        }
        return false;
    }// فنكشن لتسجيل الطالب في الكورس المتاح 
    //بعمل فحص ازا موجود الكورس انه يكون متاح وازا بقدر الطالب يسجل فيه
    //ازا نعم بعمل تسجيل وازا لاء برجع فولس

    bool drop_student(Student* student, Course* course) {
        if (std::find(courses.begin(), courses.end(), course) != courses.end() && std::find(students.begin(), students.end(), student) != students.end()) {
            return course->drop_student(student);
        }
        return false;
    }// انسحاب الطالب من الكورس 
    //نفس طريقة فحص التسجيل في كورس 

       std::vector<std::string> generate_course_report() {
        std::vector<std::string> report;
        for (Course* course : courses) {
            report.push_back("Course Code: " + course->course_code);
            report.push_back("Title: " + course->title);
            report.push_back("Enrolled Students: " + std::to_string(course->students.size()));
        }
        return report;
    } //   تقرير لعرض اول اشي الكود الخاص بكل كورس متاح وعنوانه وايش الكورس يلي بدو يسجل فيه الطالب
    //ويعرض الطالب يلي سجل في هذا الكورس
    
}

int main(){

university u1;
student* s1=new student(1,"hadeel","amhad@gmail.com");
student* s2=new student(10,"rahaf","rahaf@gmail.com");
student* s3=new student(100,"aseel","aseel@gmail.com");

course* c1=new course("css","advance","Dr.Mustafa",50);
course* c2=new course("acc","algorithm","Dr.Amjad",40);

    university.add_student(s1);
    university.add_student(s2);
    university.add_student(s3);
    
    university.add_course(c1);
    university.add_course(c2);

    university.enroll_student(s1, c1);
    university.enroll_student(s2, c1);
    university.enroll_student(s3, c1);
    university.enroll_student(s1, c2);
    university.enroll_student(s2, c2);

    university.drop_student(s3, c1);

    delete s1;
    delete s2;
    delete s3;
    delete c1;
    delete c2;
    
    return 0;
}