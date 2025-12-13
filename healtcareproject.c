#include "healtcareproject.h"
#include <stdlib.h>

// USER AUTHENTICATION

int authenticate(struct User u, char *username, char *password)
{
    return strcmp(u.username, username) == 0 && strcmp(u.password, password) == 0;
}


// ...existing code...
{
  "configurations": [
    {
      "name": "Linux",
      "compilerPath": "/usr/bin/g++",
      "intelliSenseMode": "gcc-x64",
      "includePath": [
        "${workspaceFolder}/**",
        "/usr/include",
        "/usr/include/c++/11"
      ],
      "cppStandard": "c++17"
    }
  ],
  "version": 4
}
// ...existing code...// PERSON → PATIENT / DOCTOR / STAFF

// APPOINTMENT

void show_appointment(char *patient, char *doctor, char *date)
{
    printf("\nAppointment: %s with Dr. %s on %s\n", patient, doctor, date);
}

// REPORT

void show_report(char *patient, char *report)
{
    printf("Report: %s for %s\n", report, patient);
}

// TELEMEDICINE

void start_telemedicine(char *patient, char *doctor)
{
    printf("\nTelemedicine Session Started Between %s and Dr. %s...\n", patient, doctor);
}

// ADMIN DASHBOARD

void admin_dashboard(int p, int d, int s)
{
    printf("\n ADMIN DASHBOARD \n");
    printf("Total Patients: %d\n", p);
    printf("Total Doctors: %d\n", d);
    printf("Total Staff: %d\n", s);
    printf("===========================\n");
}

// MAIN PROGRAM

int start()
{

    // Default Admin User
    struct User admin = {"admin", "1234", "admin"};

    char in_user[50], in_pass[50];

    printf("===== LOGIN =====\n");
    printf("Username: ");
    scanf("%s", in_user);
    printf("Password: ");
    scanf("%s", in_pass);

    if (!authenticate(admin, in_user, in_pass))
    {
        printf("\nAuthentication failed!\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    // PATIENT REGISTRATION
    struct Patient patient;
    patient.report_count = 0;
    patient.appt_count = 0;

    printf("\nEnter patient name: ");
    scanf("%s", patient.name);

    printf("Enter patient age: ");
    scanf("%d", &patient.age);

    printf("Enter patient phone: ");
    scanf("%s", patient.phone);

    printf("Enter patient disease: ");
    scanf("%s", patient.disease);

    // DOCTOR REGISTRATION
    struct Doctor doctor;

    printf("\nEnter doctor name: ");
    scanf("%s", doctor.name);

    printf("Enter doctor phone: ");
    scanf("%s", doctor.phone);

    printf("Enter doctor speciality: ");
    scanf("%s", doctor.speciality);

    // STAFF REGISTRATION
    struct Staff staff;

    printf("\nEnter staff name: ");
    scanf("%s", staff.name);

    printf("Enter staff phone: ");
    scanf("%s", staff.phone);

    printf("Enter staff role: ");
    scanf("%s", staff.role);

    // APPOINTMENT
    char appt_date[50];

    printf("\nEnter appointment date (YYYY-MM-DD): ");
    scanf("%s", appt_date);

    strcpy(patient.appointments[patient.appt_count++], appt_date);
    show_appointment(patient.name, doctor.name, appt_date);

    // REPORT
    char report[50];

    printf("\nEnter report name: ");
    scanf("%s", report);

    strcpy(patient.reports[patient.report_count++], report);
    show_report(patient.name, report);

    // TELEMEDICINE
    char option[10];
    printf("\nStart Telemedicine? (yes/no): ");
    scanf("%s", option);

    if (strcmp(option, "yes") == 0)
    {
        start_telemedicine(patient.name, doctor.name);
    }

    // ADMIN DASHBOARD
    admin_dashboard(1, 1, 1);
    return 0;
}