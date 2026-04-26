#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AdminUsername "hospital"
#define Password "1234"

int login() {
	char username[50];
	char password[50];
	int attempts=3;
	
	for (int i=0;i<attempts;i++) {
	printf("Enter Username :");
	fgets(username,sizeof(username),stdin);
	username[strcspn(username,"\n")]='\0';
	
    printf("Enter Password :");
	fgets(password,sizeof(password),stdin);
	password[strcspn(password,"\n")]='\0';
	
	if(strcmp(username,AdminUsername)==0 && strcmp(password,Password)==0) {
		printf("Logged in succesfully!");
		return 1;
		} else {
		 printf("Wrong credentials! Try again.\n");
	}
	}
	
   printf("Access denied!");
}
struct patient {
    char name[100];
    int id;
    char gender[20];
    int age;
    char dob[20];  
};

struct doctor {
    char name[100];
    int doctorID;
    char gender[20];
    char doctorspecialization[100];
    float doctorfees;    
    int doctorroomno;
};

struct billing {
    int daysspent;
    int id;
    char treatment[200];  
    float amount;
    float discount;
    float taxRate;
    float totalAmount;
};

struct staff {
    int staffID;
    char name[100];
    char role[50];
    char department[50];
    char phone[15];
};


struct patient* patients = NULL;
struct doctor* doctors = NULL;
struct billing* bills = NULL;
struct staff* staffs = NULL;

int patientcount=0;
int doctorcount=0;
int staffcount=0;
int billcount=0;

int patientid=0;
int doctorid=0;
int billid=0;
int staffid=0;


void addpatient();
void adddoctor();
void addstaff();
void generatebill();
void deletedoctor();
void deletestaff();
void deletepatient();
void displaystaff();
void displaydoctors();
void displaypatients();
void searchpatient();

void addpatient() {
struct patient newpatient;
patients = (struct patient*) realloc(patients, sizeof(struct patient) * (patientcount + 1));
if (patients == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

do {

printf("Enter patient name :");
fgets(newpatient.name,sizeof(newpatient.name),stdin);
newpatient.name[strcspn(newpatient.name, "\n")] = '\0';
if (strlen(newpatient.name) == 0) {
        printf("Name cannot be empty. Please try again.\n");
    }
} while (strlen(newpatient.name) == 0);

 newpatient.id = ++patientid;

    printf("Generated Patient ID: %d\n", newpatient.id);
do{
printf("Enter patient gender :");
fgets(newpatient.gender,sizeof(newpatient.gender),stdin);
newpatient.gender[strcspn(newpatient.gender, "\n")] = '\0';
if (strlen(newpatient.gender) == 0 || (strcmp(newpatient.gender, "Male") != 0 && strcmp(newpatient.gender, "Female") != 0)) {
            printf("Invalid gender! Please enter 'Male' or 'Female'.\n");
        }
    } while (strcmp(newpatient.gender, "Male") != 0 && strcmp(newpatient.gender, "Female") != 0);


printf("Enter patient date of birth(DD/MM/YY): ");
    fgets(newpatient.dob, sizeof(newpatient.dob), stdin);
    newpatient.dob[strcspn(newpatient.dob, "\n")] = '\0';
   
   
   
printf("Enter patient age :");
  while (scanf("%d", &newpatient.age) != 1 || newpatient.age < 0 || newpatient.age > 120) {
    printf("Invalid input! Please enter a valid age (0-120): ");
    while (getchar() != '\n'); 
}
getchar();


patients[patientcount++]=newpatient;
printf("Patient added succesfully!\n");


  FILE *patientfile=fopen("patients.txt","a");
  if(!patientfile) {
  	printf("Error opening the patients file for saving\n");
  	return;
  }
  fprintf(patientfile, "%d\n%s\n%s\n%s\n%d\n", newpatient.id, newpatient.name, newpatient.gender, newpatient.dob, newpatient.age);

    fclose(patientfile);
}



void adddoctor() {
struct doctor newdoctor;
 doctors = (struct doctor*) realloc(doctors, sizeof(struct doctor) * (doctorcount + 1));
  if (doctors == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
do {
printf("Enter doctor name :");
fgets(newdoctor.name,sizeof(newdoctor.name),stdin);
newdoctor.name[strcspn(newdoctor.name, "\n")] = '\0';
 if (strlen(newdoctor.name) == 0) {
            printf("Name cannot be empty. Please try again.\n");
        }
    } while (strlen(newdoctor.name) == 0);

 newdoctor.doctorID = ++doctorid;

    printf("Generated Doctor ID: %d\n", newdoctor.doctorID);
    
    
do{
printf("Enter doctor specialisation :");
fgets(newdoctor.doctorspecialization,sizeof(newdoctor.doctorspecialization),stdin);
newdoctor.doctorspecialization[strcspn(newdoctor.doctorspecialization, "\n")] = '\0';
 if (strlen(newdoctor.doctorspecialization) == 0) {
            printf("Specialization cannot be empty. Please try again.\n");
        }
    } while (strlen(newdoctor.doctorspecialization) == 0);
    
do{
printf("Enter doctor gender :");
fgets(newdoctor.gender,sizeof(newdoctor.gender),stdin);
newdoctor.gender[strcspn(newdoctor.gender, "\n")] = '\0';
if (strlen(newdoctor.gender) == 0 || (strcmp(newdoctor.gender, "Male") != 0 && strcmp(newdoctor.gender, "Female") != 0)) {
            printf("Invalid gender! Please enter 'Male' or 'Female'.\n");
        }
    } while (strcmp(newdoctor.gender, "Male") != 0 && strcmp(newdoctor.gender, "Female") != 0);

   
printf("Enter doctor fees :");
 while (scanf("%f", &newdoctor.doctorfees) != 1 || newdoctor.doctorfees <= 0) {
        printf("Invalid input! Please enter a valid positive number for doctor fees: ");
        while (getchar() != '\n'); 
    }
    getchar();

printf("Enter doctor room number :");
while (scanf("%d", &newdoctor.doctorroomno) != 1 || newdoctor.doctorroomno <= 0) {
        printf("Invalid input! Please enter a valid room number for the doctor: ");
        while (getchar() != '\n'); 
    }
    getchar();

doctors[doctorcount++]=newdoctor;
printf("Doctor added successfully!\n");

 FILE *doctorfile=fopen("doctors.txt","a");
  if(!doctorfile) {
  	printf("Error opening the doctors file for saving\n");
  	return;
  }
  fprintf(doctorfile, "%s\n%d\n%s\n%s\n%f\n%d\n", newdoctor.name, newdoctor.doctorID, newdoctor.doctorspecialization, newdoctor.gender, newdoctor.doctorfees,newdoctor.doctorroomno);

    fclose(doctorfile);

}


void addstaff() {
struct staff newstaff;
staffs = (struct staff*) realloc(staffs, sizeof(struct staff) * (staffcount + 1));
if (staffs == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

 newstaff.staffID = ++staffid;

    printf("Generated Staff ID: %d\n", newstaff.staffID);
    
do{
printf("Enter staff name :");
fgets(newstaff.name,sizeof(newstaff.name),stdin);
newstaff.name[strcspn(newstaff.name, "\n")] = '\0';
 newstaff.name[strcspn(newstaff.name, "\n")] = '\0';
        if (strlen(newstaff.name) == 0) {
            printf("Name cannot be empty. Please try again.\n");
        }
    } while (strlen(newstaff.name) == 0);
    
    
do{
printf("Enter staff role :");
fgets(newstaff.role,sizeof(newstaff.role),stdin);
 newstaff.role[strcspn(newstaff.role, "\n")] = '\0';
  newstaff.name[strcspn(newstaff.name, "\n")] = '\0';
        if (strlen(newstaff.name) == 0) {
            printf("Name cannot be empty. Please try again.\n");
        }
    } while (strlen(newstaff.name) == 0);
    
    
do{

printf("Enter staff department :");
fgets(newstaff.department,sizeof(newstaff.department),stdin);
newstaff.department[strcspn(newstaff.department, "\n")] = '\0';
if (strlen(newstaff.department) == 0) {
            printf("Department cannot be empty. Please try again.\n");
        }
    } while (strlen(newstaff.department) == 0);
    
    
do{
printf("Enter staff phone number :");
fgets(newstaff.phone,sizeof(newstaff.phone),stdin);
 newstaff.phone[strcspn(newstaff.phone, "\n")] = '\0';
 if (strlen(newstaff.phone) != 10) {
            printf("Invalid phone number! Please enter a 10-digit phone number.\n");
        }
    } while (strlen(newstaff.phone) != 10);
 

staffs[staffcount++]=newstaff;
printf("Staff added sucessfully!\n");

 FILE *stafffile=fopen("staffs.txt","a");
  if(!stafffile) {
  	printf("Error opening the staffs file for saving\n");
  	return;
  }
  fprintf(stafffile, "%d\n%s\n%s\n%s\n%s\n", newstaff.staffID, newstaff.name, newstaff.role, newstaff.department, newstaff.phone);

    fclose(stafffile);
   
}

void generatebill() {
struct billing newbill;
bills = (struct billing*) realloc(bills, sizeof(struct billing)* (billcount + 1));
if (bills == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

 newbill.id = ++billid;

    printf("Generated Bill ID: %d\n", newbill.id);
printf("Enter days spent :");
while (scanf("%d", &newbill.daysspent) != 1 || newbill.daysspent <= 0) {
        printf("Invalid input! Please enter a valid positive number for days spent: ");
        while (getchar() != '\n'); 
    }
    getchar();
    
do{

printf("Enter treatment :");
fgets(newbill.treatment,sizeof(newbill.treatment),stdin);
newbill.treatment[strcspn(newbill.treatment, "\n")] = '\0';
if (strlen(newbill.treatment) == 0) {
            printf("Treatment description cannot be empty. Please try again.\n");
        }
    } while (strlen(newbill.treatment) == 0);

printf("Enter amount :");
while (scanf("%f", &newbill.amount) != 1 || newbill.amount <= 0) {
        printf("Invalid input! Please enter a valid positive amount for the bill: ");
        while (getchar() != '\n'); 
    }
    
    printf("Enter discount percentage (0-100): ");
    while (scanf("%f", &newbill.discount) != 1 || newbill.discount < 0 || newbill.discount > 100) {
        printf("Invalid input! Please enter a valid discount percentage (0-100): ");
        while (getchar() != '\n');
    }

    printf("Enter tax rate percentage (0-100): ");
    while (scanf("%f", &newbill.taxRate) != 1 || newbill.taxRate < 0 || newbill.taxRate > 100) {
        printf("Invalid input! Please enter a valid tax rate percentage (0-100): ");
        while (getchar() != '\n');
    }
getchar();
    
    newbill.totalAmount = (newbill.amount * (1 - newbill.discount / 100)) * (1 + newbill.taxRate / 100); 
    printf("\nTotal Bill Amount: %.2f\n", newbill.totalAmount);

bills[billcount++]=newbill;
printf("Bill generated successfully!\n");

 FILE *billfile=fopen("bills.txt","a");
  if(!billfile) {
  	printf("Error opening the bills file for saving\n");
  	return;
  }
  fprintf(billfile, "%d\n%s\n%f\n", newbill.daysspent, newbill.treatment, newbill.amount);

    fclose(billfile);
    
    


}
 
 void searchpatient() {
 	int id;
	printf("Enter Patient ID(XX) to search :");
	if (scanf("%d", &id) != 1) {
        printf("Invalid ID format. Please enter a valid number.\n");
        return;
    }
 	
 	FILE *patientfile=fopen("patients.txt","r");
    if (patientfile==NULL) {
    	printf("No patients to display!");
    	return;
	}
	for (int i = 0; i < patientcount; i++) {
        if (patients[i].id == id) {
            printf("Patient found: %s\n", patients[i].name);
            printf("ID: %d\n", patients[i].id);
            printf("Gender: %s\n", patients[i].gender);
            printf("Date of Birth: %s\n", patients[i].dob);
            printf("Age: %d\n", patients[i].age);
            return;
        }
    }
    printf("Patient with ID %d not found.\n", id);
	
 	
 }

void displaypatients() {
	
	
	
	FILE *patientfile=fopen("patients.txt","r");
    if (patientfile==NULL) {
    	printf("No patients to display!");
    	return;
	}
	
	printf("\n-------------Patient List-------------\n");
	for(int i=0; i<patientcount;i++) {
		printf("Patient name :%s\n",patients[i].name);
		printf("Patient ID :%d\n",patients[i].id);
		printf("Patient gender :%s\n",patients[i].gender);
		printf("Patient age :%d\n",patients[i].age);
		printf("Patient date of birth :%s\n",patients[i].dob);
		
	}
	
}

void displaydoctors(){
	   FILE *doctorfile=fopen("doctors.txt","r");
    if(doctorfile==NULL) {
    	printf("No doctors to display!");
    	return;
	}

	
	printf("\n-------------Doctors List-------------\n");
	for(int i=0; i<patientcount;i++) {
		printf("Doctor name :%s\n",doctors[i].name);
		printf("Doctor ID :%d\n",doctors[i].doctorID);
		printf("Doctor gender :%s\n",doctors[i].gender);
		printf("Doctor specialisation' :%s\n",doctors[i].doctorspecialization);
		printf("Doctor fees :%f\n",doctors[i].doctorfees);
		printf("Doctor room number :%d\n",doctors[i].doctorroomno);
	
}
}

void displaystaff() {
	
	  FILE *stafffile=fopen("staffs.txt","r");
    if(stafffile==NULL) {
    	printf("No staff to display!");
    	return;
	}
	printf("\n-------------Staff List-------------\n");
	for (int i=0;i<staffcount;i++) {
			printf("Staff name :%s\n",staffs[i].name);
			printf("Staff ID :%d\n",staffs[i].staffID);
			printf("Staff role :%s\n",staffs[i].role);
			printf("Staff department :%s\n",staffs[i].department);
			printf("Staff phone number :%s\n",staffs[i].phone);
	}
}
  

void deletedoctor() {
	int id;
	printf("Enter Doctor ID(XX) to delete :");
if (scanf("%d", &id) != 1) {
        printf("Invalid ID format. Please enter a valid number.\n");
        return;
    }
    
    if (doctorcount == 0) {
        printf("No doctors available for deletion.\n");
        return;
    }
	
	for(int i=0; i<doctorcount; i++) {
		if (doctors[i].doctorID==id) {
			for(int j=i;j<doctorcount-1;j++) {
				doctors[j]=doctors[j+1];
			}
			doctorcount--;
			printf("Doctor deleted succesfully!\n");
			return;
		}
		
	}
	printf("Doctor with %d ID not found",id);
}

void deletepatient() {
	int id;
	printf("Enter Patient ID(XX) to delete :");
	if (scanf("%d", &id) != 1) {
        printf("Invalid ID format. Please enter a valid number.\n");
        return;
    }
    
     if (patientcount == 0) {
        printf("No patients available for deletion.\n");
        return;
    }
	
	
	for(int i=0;i<patientcount;i++) {
		if (patients[i].id==id) {
			for(int j=i;j<patientcount-1;j++) {
				patients[j]=patients[j+1];
			}
			patientcount--;
			printf("Patient deleted succesfully!\n");
			return;
		}
		
	}
	printf("Patient with %d ID not found",id);
}

void deletestaff() {
	int id;
	printf("Enter Staff ID(XX) to delete :");
	if (scanf("%d", &id) != 1) {
        printf("Invalid ID format. Please enter a valid number.\n");
        return;
    }
    
	
	 if (staffcount == 0) {
        printf("No staff available for deletion.\n");
        return;
    }
	
	
	for(int i=0;i<staffcount;i++) {
		if (staffs[i].staffID==id) {
			for(int j=i;j<staffcount-1;j++) {
				staffs[j]=staffs[j+1];
			}
			staffcount--;
			printf("Staff deleted succesfully!\n");
			return;
		}
		
	}
	printf("Staff with %d ID not found",id);
}







 


int main() {
     
     if(login()==0) {
     	printf("Failed to login!");
     	return 0;
	 }
int choice;

 do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Add Staff\n");
        printf("4. Generate Bill\n");
        printf("5. Display Patients\n");
        printf("6. Display Doctors\n");
        printf("7. Display Staff\n");
        printf("8. Delete Patient\n");
        printf("9. Delete Doctor\n");
        printf("10. Delete Staff\n");
        printf("11. Search Pateint\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice<0) {
        	printf("Invalid choice!");
        	while (getchar() != '\n');
            continue; 
        }

       while (getchar() != '\n');
       
      switch(choice) {
      case 1:
 addpatient();
  break;
      case 2:
 adddoctor();
 break;
     case 3:
  addstaff();
  break;
        case 4:
 generatebill();
 break;
        case 5:
 displaypatients();
 break;
        case 6:
 displaydoctors();
 break;
        case 7:
 displaystaff();
 break;
case 8:
 deletepatient();
 break;
        case 9:
 deletedoctor();
 break;
        case 10:
 deletestaff();
 break;
        case 11:
 searchpatient();
 break;
        case 0:
 printf("Exiting program...\n");
break;
        default: printf("Invalid choice! Please try again.\n");
 }  
    }
    while(choice!=0);
    
    
    return 0;
   
}
