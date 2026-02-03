#include <iostream>
using namespace std;

struct sNode {
    string data;
    sNode* next;
};
sNode* sList = NULL;

struct cNode {
    string data;
    cNode* next;
    sNode* studentList;
};
cNode* cList= NULL;

void insertCourse(string courseNo) {
    cNode * node= new cNode();
    node->data = courseNo;
    node->next = NULL;
    node->studentList = NULL;
    if (cList == NULL) {
        cList = node;
        return;
    }
    cNode* temp = cList;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

cNode* searchCourse(string courseNo) {
    cNode * temp = cList;
    if (cList==NULL) {
        cout<<"Course List is empty"<<endl;
        return NULL;
    }

    while (temp != NULL) {
        if (temp->data == courseNo) {
             cout<<"Course Found "<<endl;
            return  temp;
        }
        temp = temp->next;
    }
    cout << "Course Not Found" << endl;
    return NULL;
}

sNode* searchStudent(string studentNo) {
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return NULL;
    }

    cNode* coursePtr = cList;

    while (coursePtr != NULL) {
        sNode* studentPtr = coursePtr->studentList;

        while (studentPtr != NULL) {
            if (studentPtr->data == studentNo) {
                cout << "Student Found! Enrolled in course: "
                     << coursePtr->data << endl;
                return studentPtr;
            }
            studentPtr = studentPtr->next;
        }

        coursePtr = coursePtr->next;
    }

    cout << "Student not found in any course!" << endl;
    return NULL;
}

sNode* searchStudentInCourse(string courseNo, string studentNo) {
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return NULL;
    }

    cNode* coursePtr = searchCourse(courseNo);
    if (coursePtr == NULL) {
        cout << "Course not found!" << endl;
        return NULL;
    }

    sNode* studentPtr = coursePtr->studentList;

    if (studentPtr == NULL) {
        cout << "No students enrolled in this course" << endl;
        return NULL;
    }

    while (studentPtr != NULL) {
        if (studentPtr->data == studentNo) {
            cout << "Student Found in course: " << courseNo << endl;
            return studentPtr;
        }
        studentPtr = studentPtr->next;
    }

    cout << "Student not found in this course" << endl;
    return NULL;
}

void addStudentInCourse(string courseNo, string studentNo) {

    cNode* course = searchCourse(courseNo);
    if (course == NULL) {
        cout << "Course is not Available!" << endl;
        return;
    }


    sNode * node = new sNode();
    node->data = studentNo;
    node->next = NULL;

    if (course->data == courseNo) {
        if (course->studentList == NULL) {
            course->studentList= node;
            return;
        }
        sNode* cur= course->studentList;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }

}

void delCourse(string courseNo) {
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return;
    }
    cNode *curr = cList;
    cNode *prev = NULL;
    while (curr!=NULL && curr->data != courseNo) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Course not found!" << endl;
        return;
    }
    sNode * sTemp= curr->studentList;
    while (sTemp!=NULL) {
        sNode* toDelete = sTemp;
        sTemp = sTemp->next;
        delete toDelete;
    }
    if (prev == NULL) {
        // Deleting head course
        cList = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << "Course deleted successfully!" << endl;

}

void deleteStudentFromCourse(string courseNo, string studentNo) {
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return;
    }

    cNode* coursePtr = searchCourse(courseNo);
    if (coursePtr == NULL) return;

    sNode* curr = coursePtr->studentList;
    sNode* prev = NULL;

    while (curr != NULL && curr->data != studentNo) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Student not found in this course" << endl;
        return;
    }

    if (prev == NULL) {
        coursePtr->studentList = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    cout << "Student deleted from course " << courseNo << endl;
}
void delStudent(string studentNo) {
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return;
    }

    cNode* coursePtr = cList;
    bool deleted = false;

    while (coursePtr != NULL) {
        sNode* curr = coursePtr->studentList;
        sNode* prev = NULL;

        while (curr != NULL) {
            if (curr->data == studentNo) {
                // 🔹 Delete node
                if (prev == NULL) {
                    // Student is head of the list
                    coursePtr->studentList = curr->next;
                } else {
                    prev->next = curr->next;
                }

                sNode* temp = curr;
                curr = curr->next; // move forward before deletion
                delete temp;
                deleted = true;
                cout << "Deleted student " << studentNo << " from course " << coursePtr->data << endl;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        coursePtr = coursePtr->next;
    }

    if (!deleted) {
        cout << "Student " << studentNo << " not found in any course" << endl;
    }
}

void displayCourse() {
    cNode * temp = cList;
    if (cList == NULL) {
        cout << "Course List is empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " -- ";
        temp = temp->next;
    }
    cout << endl;
}
void displayStudentList() {
    if (cList == NULL) {
        cout << "No courses available." << endl;
        return;
    }

    cNode* coursePtr = cList;

    while (coursePtr != NULL) {
        cout << "Course: " << coursePtr->data << " → ";

        sNode* studentPtr = coursePtr->studentList;
        if (studentPtr == NULL) {
            cout << "No students enrolled." << endl;
        } else {
            while (studentPtr != NULL) {
                cout << studentPtr->data;
                if (studentPtr->next != NULL)
                    cout << " → ";
                studentPtr = studentPtr->next;
            }
            cout << endl;
        }

        coursePtr = coursePtr->next;
    }
}

void displayALl() {
    cNode * temp = cList;

    if (temp == NULL) {
        cout << "No courses available\n";
        return;
    }
    while (temp !=NULL) {
        cout << temp->data << " --  " ;
        sNode * stdtemp = temp->studentList;

        if (stdtemp== NULL) {
            cout << "Empty!" << endl;
        }
        else {
            while (stdtemp != NULL) {
                cout <<stdtemp->data << " --" ;
                stdtemp = stdtemp->next;
            }
        }
        cout << endl;
        temp= temp->next;
    }

}

int main() {
    cout << "Welcome to MULTI LL" << endl;

    insertCourse("Course1");
    insertCourse("Course2");
    insertCourse("Course3");

    addStudentInCourse("Course2", "alishba");
    addStudentInCourse("Course1", "ali");
    addStudentInCourse("Course2", "alishbaSyeda");
    searchCourse("Course1");
    searchCourse("Course4");
    displayALl();
    cout << "----------Displaying courses ---------" << endl;
    displayCourse();
    return 0;
}