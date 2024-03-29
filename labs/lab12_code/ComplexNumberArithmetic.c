/* Implementation of Type and Operators for Complex Number Arithmetic */
/*
 * Operators to process complex numbers
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

/*  User-defined complex number type */
typedef struct {
    double real;
    double imaginary;
} complex_t;

int driver(void);

int scan_complex(complex_t *c);

void print_complex(complex_t c);

complex_t add_complex(complex_t c1, complex_t c2);

complex_t subtract_complex(complex_t c1, complex_t c2);

complex_t multiply_complex(complex_t c1, complex_t c2);

complex_t divide_complex(complex_t c1, complex_t c2);
complex_t divide_complex_a(complex_t c1, complex_t c2);

complex_t abs_complex(complex_t c);

complex_t complex_conjugate(complex_t c);

int main(void) {
    char c[2] = "y";
    while (strncmp(c, "y", strlen("y")) == 0) {
        driver();

        printf("\nWould you like to compute another?\n(y/n) > ");
        // this is unsafe and i literally do not care
        fscanf(stdin, "%s", &c);
    }
    printf("Exiting...\n");
}

/* Driver                                                               */
int driver(void) {
    complex_t com1, com2;

    /* Gets two complex numbers                                       */
    printf("Enter the real and imaginary parts of a complex number\n");
    printf("separated by a space > ");
    scan_complex(&com1);
    printf("Enter a second complex number > ");
    scan_complex(&com2);

    char choice[2];
    printf("Menu:\n\n");
    printf("a. add the numbers\n");
    printf("s. subtract the numbers\n");
    printf("m. multiply the numbers\n");
    printf("d. divide the numbers\n");
    printf("v. get the absolute value\n");
    printf("c. get the complex conjugate\n\n");
    printf("(a/s/m/d/v/c) > ");
    fscanf(stdin, "%s", &choice);

    size_t len = strlen("a");
    if (strncmp(choice, "a", len) == 0) {
        /* Forms and displays the sum                                     */
        printf("\n");
        print_complex(com1);
        printf(" + ");
        print_complex(com2);
        printf(" = ");
        print_complex(add_complex(com1, com2));
    } else if (strncmp(choice, "s", len) == 0) {
        /* Forms and displays the difference                              */
        printf("\n\n");
        print_complex(com1);
        printf(" - ");
        print_complex(com2);
        printf(" = ");
        print_complex(subtract_complex(com1, com2));
    } else if (strncmp(choice, "m", len) == 0) {
        /* Forms and displays the product                              */
        printf("\n\n");
        print_complex(com1);
        printf(" * ");
        print_complex(com2);
        printf(" = ");
        print_complex(multiply_complex(com1, com2));
    } else if (strncmp(choice, "d", len) == 0) {
        /* Forms and displays the quotient                              */
        printf("\n\n");
        print_complex(com1);
        printf(" / ");
        print_complex(com2);
        printf(" = ");
        print_complex(divide_complex(com1, com2));
        printf("\nmy function:\n");
        print_complex(divide_complex_a(com1, com2));
    } else if (strncmp(choice, "v", len) == 0) {
        /* Forms and displays the absolute value of the first number      */
        printf("\n\n|");
        print_complex(com1);
        printf("| = ");
        print_complex(abs_complex(com1));
    } else if (strncmp(choice, "c", len) == 0) {
        /* Forms and displays the complex conjugate */
        printf("\n\n");
        print_complex(com1);
        printf(" -> ");
        print_complex(complex_conjugate(com1));
        printf("\n");
    }

    return (0);
}

/*
 * Complex number input function returns standard scanning error code
 * 1 => valid scan, 0 => error, negative EOF value => end of file
 */
int scan_complex(complex_t *c) /* output - address of complex variable to
                                       fill                             */
{
    int status;

    status = scanf("%lf%lf", &c->real, &c->imaginary);
    if (status == 2)
        status = 1;
    else if (status != EOF)
        status = 0;

    return (status);
}

/*
 * Complex output function displays value as (a + bi) or (a - bi),
 * dropping a or b if they round to 0 unless both round to 0
 */
void print_complex(complex_t c) /* input - complex number to display     */
{
    double a, b;
    char sign;

    a = c.real;
    b = c.imaginary;

    printf("(");

    if (fabs(a) < .005 && fabs(b) < .005) {
        printf("%.2f", 0.0);
    } else if (fabs(b) < .005) {
        printf("%.2f", a);
    } else if (fabs(a) < .005) {
        printf("%.2fi", b);
    } else {
        if (b < 0)
            sign = '-';
        else
            sign = '+';
        printf("%.2f %c %.2fi", a, sign, fabs(b));
    }

    printf(")");
}

/*
 * Returns sum of complex values c1 and c2
 */
complex_t add_complex(complex_t c1, complex_t c2) /* input - values to add      */
{
    complex_t csum;

    csum.real = c1.real + c2.real;
    csum.imaginary = c1.imaginary + c2.imaginary;
    return (csum);
}

/*
 * Returns difference c1 - c2
 */
complex_t subtract_complex(complex_t c1, complex_t c2) /* input parameters      */
{
    complex_t cdiff;
    cdiff.real = c1.real - c2.real;
    cdiff.imaginary = c1.imaginary - c2.imaginary;

    return (cdiff);
}

/* 
 * Returns product of complex values c1 (a + bi) and c2 (c+di) :c1*c2 = (ac−bd)+(ad+bc)i
 */
complex_t multiply_complex(complex_t c1, complex_t c2) /* input parameters      */
{
    complex_t cprod;
    cprod.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    cprod.imaginary = (c1.real * c2.imaginary) + (c2.imaginary * c2.real);
    //printf("Function multiply_complex returning c1*c2\n");
    return (cprod);
}

/* ** Stub **
 * Returns quotient of complex values (c1 / c2)
 */
complex_t divide_complex(complex_t c1, complex_t c2) /* input parameters     */
{
    complex_t c2_conjugate, cquot;
    double denom;

    //printf("Function divide_complex returning c1/c2\n");
    // compute the complex conjugate of the divisor c2.real - c2.imaginary
    c2_conjugate.real = c2.real;
    c2_conjugate.imaginary = -1 * c2.imaginary;
    //compute numerator of quotient

    denom = c2_conjugate.real * c2_conjugate.real + c2_conjugate.imaginary * c2_conjugate.imaginary;
    if (denom == 0.0) {
        fprintf(stderr, "Denominator was zero.\n");
        cquot.real = 0;
        cquot.imaginary = 0;
        return cquot;
    }

    cquot.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denom;
    cquot.imaginary = (c1.real * c2.imaginary - c2.real * c1.imaginary) / denom;
    //printf("Function divide_complex returning c1/c2\n")
    return (cquot);
}

complex_t divide_complex_a(complex_t c1, complex_t c2) {
    complex_t cquot;

    complex_t c2_conjugate = complex_conjugate(c2);
    double denominator = multiply_complex(c2, c2_conjugate).real;

    complex_t numerator = multiply_complex(c1, c2_conjugate);

    double real = numerator.real / denominator;
    double imaginary = numerator.imaginary / denominator;

    cquot.real = real;
    cquot.imaginary = imaginary;

    //printf("Function divide_complex returning c1/c2\n")
    return (cquot);
}

/*
 * Returns absolute value of complex number c
 */
complex_t abs_complex(complex_t c) /* input parameter                        */
{
    complex_t cabs;

    cabs.real = sqrt(c.real * c.real + c.imaginary * c.imaginary);
    cabs.imaginary = 0;

    return (cabs);
}

complex_t complex_conjugate(complex_t c) {
    complex_t ccjg;

    ccjg.real = c.real;
    ccjg.imaginary = c.imaginary * -1;
    return ccjg;
}

/*
Enter the real and imaginary parts of a complex number
separated by a space> 3.5 5.2
Enter a second complex number> 2.5 1.2
(3.50 + 5.20i) + (2.50 + 1.20i) = (6.00 + 6.40i)
(3.50 + 5.20i) - (2.50 + 1.20i) = (1.00 + 4.00i)
|(3.50 + 5.20i)| = (6.27)
*/


