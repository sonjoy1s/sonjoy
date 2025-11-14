#include <stdio.h>
#include <string.h>

// Person Structure
struct Person {
    char name[50];
    char phone[20];
};
// Patient Structure
struct Patient {
    struct Person person;
    int age;
    char disease[50];
    char reports[10][50];
    int report_count;
};

// Doctor Structure
struct Doctor {
    struct Person person;
    char speciality[50];
};

// Appointment Structure
struct Appointment {
    struct Patient *patient;
    struct Doctor *doctor;
    char date[20];
};

struct Report {
    struct Patient *patient;
    char report_name[50];
};

void show_info(struct Person p) {
    printf("Name: %s, Phone: %s\n", p.name, p.phone);
}

void add_report(struct Patient *pat, char report[]) {
    strcpy(pat->reports[pat->report_count], report);
    pat->report_count++;
}

void show_appointment(struct Appointment appt) {
    printf("\n----\n");
    printf(" Appointment Details\n");
    printf("---------------------------------\n");
    printf("Patient: %s\n", appt.patient->person.name);
    printf("Doctor: Dr. %s\n", appt.doctor->person.name);
    printf("Date  : %s\n", appt.date);
    printf("----\n\n");
}

void show_report(struct Report r) {
    printf("\n==Report==\n");
    printf("Report Name: %s\n", r.report_name);
    printf("Patient    : %s\n", r.patient->person.name);
    printf("\n");
}

int main() {

    struct Patient patient;
    struct Doctor doctor;
    struct Appointment appointment;
    struct Report report;

    printf("Enter patient name: ");
    scanf(" %[^\n]", patient.person.name);

    printf("Enter patient age: ");
    scanf("%d", &patient.age);

    printf("Enter patient phone: ");
    scanf(" %[^\n]", patient.person.phone);

    printf("Enter patient disease: ");
    scanf(" %[^\n]", patient.disease);

    patient.report_count = 0;

    // Doctor Section
    printf("\nEnter doctor name: ");
    scanf(" %[^\n]", doctor.person.name);

    printf("Enter doctor phone: ");
    scanf(" %[^\n]", doctor.person.phone);

    printf("Enter doctor speciality: ");
    scanf(" %[^\n]", doctor.speciality);

    // Appoinment Section
    printf("\nEnter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]", appointment.date);

    appointment.patient = &patient;
    appointment.doctor  = &doctor;

    // Show appointment
    show_appointment(appointment);

    // Report Section
    printf("Enter report name: ");
    scanf(" %[^\n]", report.report_name);

    report.patient = &patient;

    add_report(&patient, report.report_name);

    show_report(report);

    return 0;
}