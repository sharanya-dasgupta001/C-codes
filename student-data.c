/* Solution to 22-back/Q3 */
#include "common.h"

#define BUF_LEN 256

typedef struct {
    char roll[7];
    char back;
    char name[BUF_LEN];
    long long int mobile; // NOTE: mobile is 10 digits long
    char email[BUF_LEN];
} STUDENT_DATA;

/* comparator routine used in qsort() to sort STUDENT_DATA by roll number */
static int compare_roll(const void *v1, const void *v2)
{
    STUDENT_DATA *s1 = v1, *s2 = v2;

    return strcmp(s1->roll, s2->roll);
}

/* comparator routine used in bsearch() to search for a given
 * roll number (string) in a STUDENT_DATA array sorted by roll number */
static int search_roll(const void *r, const void *s)
{
    char *roll = *((char **) r);
    STUDENT_DATA *student = s;

    return strcmp(roll, student->roll);
}


int main(int ac, char *av[])
{
    char inbuf[BUF_LEN], *ptr;
    int num_students, i;
    STUDENT_DATA *student_data, *sptr;

    if (1 != scanf("%d\n", &num_students)) /* \n after %d gets rid of any
                                            * trailing whitespace */
        ERR_MESG("Invalid input");
    if (NULL == (student_data = Malloc(num_students, STUDENT_DATA)))
        ERR_MESG("backpaper: out of memory\n");

    for (i = 0; i < num_students; i++) {
        /* read the whole line (not more than 128 characters) */
        if (NULL == fgets(inbuf, BUF_LEN, stdin))
            ERR_MESG("Invalid input");
        /* field 1: roll number */
        if (NULL == (ptr = strtok(inbuf, ",\n")))
            ERR_MESG("Invalid input");
        strncpy(student_data[i].roll, ptr, 7);
        /* field 2: name */
        if (NULL == (ptr = strtok(NULL, ",\n")))
            ERR_MESG("Invalid input");
        strncpy(student_data[i].name, ptr, BUF_LEN-1);
        /* field 3: mobile number */
        if (NULL == (ptr = strtok(NULL, ",\n")))
            ERR_MESG("Invalid input");
        student_data[i].mobile = atoll(ptr);
        /* field 4: email address */        
        if (NULL == (ptr = strtok(NULL, ",\n")))
            ERR_MESG("Invalid input");
        strncpy(student_data[i].email, ptr, BUF_LEN-1);
        student_data[i].back = 0;
    }
    qsort(student_data, num_students, sizeof(STUDENT_DATA), compare_roll);
#ifdef DEBUG
    /* verify whether input has been read and sorted as desired */
    for (i = 0; i < num_students; i++)
        printf("%s,%s,%lld,%s\n",
               student_data[i].roll,
               student_data[i].name,
               student_data[i].mobile,
               student_data[i].email);
#endif

    /* read marks (don't need to store this information for this
     * particular question)
     */
    for (i = 0; i < num_students; i++) {
        if (NULL == fgets(inbuf, BUF_LEN, stdin))
            ERR_MESG("Invalid input");
        /* field 1: roll number */
        if (NULL == (ptr = strtok(inbuf, ",\n")))
            ERR_MESG("Invalid input");
        /* locate the data of the student with this roll number */
        if (NULL == (sptr = bsearch((const void *) &ptr, 
                                    (const void *) student_data, num_students,
                                    sizeof(STUDENT_DATA),
                                    search_roll)))
            ERR_MESG("Student not found");
        /* read marks in each course taken and check whether < 35 */
        while (NULL != (ptr = strtok(NULL, ",\n"))) {
            char *cptr;
            if (ptr[0] == '\0') continue;  // empty field (like ,,)
            int marks = strtoll(ptr, &cptr, 10);
            if (cptr[0] != '\0')           // just checking
                ERR_MESG("Invalid marks");
            if (marks < 35)
                sptr->back = 1;
        }
    }

    for (i = 0; i < num_students; i++)
        if (student_data[i].back)
            printf("%s\n", student_data[i].email);

    free(student_data);
    return 0;
}
#include<lim
