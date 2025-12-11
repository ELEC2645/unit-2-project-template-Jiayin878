
#include "funcs.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
static int getrightinputvalue(void);
static int back_mainormenu(void);
static int  is_integer(const char *s);
static int back_mainordoquziagain(void);
int is_double_string(const char *s);
void flush_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
}
static int getrightinputvalue_for_menu5_item2(void)
{
    enum { MENU_ITEMS = 3 };   /* 1..4 */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("Select item (1-%d): ", MENU_ITEMS);
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item! \n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}
static int get_user_input_menu_5(void)
{
    enum { MENU_ITEMS = 4 };   /* 1..4 */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("Select item (1-%d): ", MENU_ITEMS);
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item! \n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

int is_double_string(const char *s){
    if (s == NULL || *s == '\0') {
        return 0; // empty string is not a number
    }

    const char *p = s;

    // Optional sign
    if (*p == '+' || *p == '-') {
        p++;
    }

    // Must have at least one digit after optional sign
    if (*p == '\0') {
        return 0;
    }
    if (*p == '.' && *(p + 1) == '\0') {
        return 0;}
        int number_of_dot=0;

    // All remaining characters must be digits
    while (*p != '\0') {
        if (*p == '.') {
            if (number_of_dot > 0) {
                return 0; // Second dot found (e.g. 1.2.3)
            }
            number_of_dot++;
        } 
        else if (*p < '0' || *p > '9') {
            return 0; // Illegal character (e.g. 5a)
        }
        p++;
    }
    
    

    // if we reach here, the input is valid
    return 1;
}
void ask_float_number(double *out_number){
    char line[64];
    
    while(1) {
        printf("Enter an float number: ");
        if (!fgets(line, sizeof line, stdin)) {
            exit(1);
        }
        if (strchr(line, '\n') == NULL) {
            flush_input_buffer();
        }
        line[strcspn(line, "\n")] = '\0';

        if (!is_double_string(line)) {
            printf("Invalid number, please try again.\n");
            continue;
        }
        *out_number = strtod(line, NULL);
        return;
    }
}
static char getanswer(void)
{
    char buf[64];
    char ch = '\0';

    do {
        printf("Enter a choice (a, b, c or d): \n");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }

        
        buf[strcspn(buf, "\r\n")] = '\0';/* strip newline */
        if (buf[0] == '\0' || buf[1] != '\0') {
            printf("Invalid input.\n");
            continue;
        }

        ch = buf[0];

        if (isdigit((unsigned char)ch)) {
            printf("Please enter a letter.\n");
            continue;
        }

        if (isalpha((unsigned char)ch)) {
            ch = (char)tolower((unsigned char)ch);
            if (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd') {
                return ch;  
            } else {
                printf("Please enter a, b, c or d.\n");
                continue;
            }
        }
        printf("Invalid input.\n");
   } while (1);
}

static int back_mainormenu(void)
{
    char buf[128];

    while (1) {
        printf("\nPress 'b or B' (back to main menu) or 'c or C' (back to this menu): ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
        if ((buf[0] == 'b' || buf[0] == 'B') && buf[1] == '\0') {
            break; 
        }
        if ((buf[0] == 'c' || buf[0] == 'C') && buf[1] == '\0') {
            break; 
        }
        printf("Invalid input. Please entry B b or C c.\n");
    } if (buf[0] == 'b' || buf[0] == 'B') {
        return 1; 
    } else {
        return 0; 
    }
}
static int back_mainordoquziagain(void)
{
    char buf[128];

    while (1) {
        printf("\nPress 'b or B' (back to main menu) or 'c or C' (Do the quiz again): ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
        if ((buf[0] == 'b' || buf[0] == 'B') && buf[1] == '\0') {
            break; 
        }
        if ((buf[0] == 'c' || buf[0] == 'C') && buf[1] == '\0') {
            break; 
        }
        printf("Invalid input. Please entry B b or C c.\n");
    } if (buf[0] == 'b' || buf[0] == 'B') {
        return 1; // return to main menu
    } else {
        return 0; // DO quiz again
    }
}

static int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}
static int getrightinputvalue(void)
{
    enum { MENU_ITEMS = 4 };   /* 1..4 */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("Select item (1-%d): ", MENU_ITEMS);
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item! \n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}
static void explain_ohms_law(void) {
printf("\n--- 1. Ohm's Law ---\n");
printf("Ohm's Law describes the relationship between Voltage (V), Current (I), and Resistance (R).\n");
printf("Formula: V = I * R\n");
printf(" - V: Voltage (Volts) - the 'pressure' in a circuit\n");
printf(" - I: Current (Amps) - the 'flow rate' of electric charge\n");
printf(" - R: Resistance (Ohms) - the 'opposition' to current flow\n");
printf("Example: If a 10 Ohm resistor has a current of 2 Amps flowing through it, the voltage across it is V = 2A * 10Ω = 20V.\n");;
}

static void explain_series_parallel(void) {
    printf("\n--- 2. Series/Parallel Resistors ---\n");
    printf("Series Connection:\n");
    printf(" - Resistors are said to be in series whenever the current flows through the resistors sequentially.\n");
    printf(" - Total resistance: R_total = R1 + R2 + ... + Rn\n");
    printf(" - Example: A 20-ohm resistor in series with a 20-ohm resistor gives\n");
    printf("   R_total = 20Ω + 20Ω = 40Ω.\n\n");
    printf("Parallel Connection:\n");
    printf(" - Resistors are in parallel when one end of all the resistors are connected by a continuous\n");
    printf("   wire of negligible resistance and the other end of all the resistors are also connected to\n");
    printf("   one another through a continuous wire of negligible resistance.\n");
    printf(" - Total resistance: 1 / R_total = (1 / R1) + (1 / R2) + ...\n");
    printf(" - Formula for two resistors: R_total = (R1 * R2) / (R1 + R2)\n");
    printf(" - Example: Two 10-ohm resistors in parallel give\n");
    printf("   R_total = (10Ω * 10Ω) / (10Ω + 10Ω) = 100 / 20 = 5Ω.\n");
}
static void explain_voltage_divider(void) {
    printf("\n--- 3. Voltage Divider ---\n");
    printf("a voltage divider (also known as a potential divider) is a passive linear circuit \n");
    printf("It produces an output voltage (Vout) that is a fraction of its input voltage (Vin)\n");
    printf("It consists of two resistors (R1 and R2) connected in series.\n");
    printf(" - Vin is applied across the series combination of R1 and R2.\n");
    printf(" - Vout is the voltage measured across R2.\n");
    printf("Equation: Vout = Vin * (R2 / (R1 + R2))\n\n");
    printf("Example:\n");
    printf("Vin = 10 V, R1 = 1 kΩ, R2 = 1 kΩ\n");
    printf("Vout = 10V * (1000 / (1000 + 1000))\n");
    printf("     = 5V\n");
}
static void ohms_law_Calculation(void){
    printf("\n---ohms_law_calculation ---\n");
    printf("up to two decimal places\n");
    printf("make your choice\n 1. V\n 2. I\n 3. R\n 4.Return to the Main Menu or go back to Menu item5\n");
    int value=get_user_input_menu_5();
    if (value==1){double I, R, V;
       while(1) {printf("Enter your I(A)\n");
        ask_float_number(&I);
        if(I>0)
        break;
    printf("Current must be greater than 0\n");}
        while(1){
            printf("Enter your R(ohms)\n");
            ask_float_number(&R);
            if(R>0) break;
            printf("Resistance must be greater than 0\n");
        }V=I*R;
        printf("Voltage = I * R = %.2f A * %.2f ohms = %.2f V\n", I, R, V);}
    else if (value==2){double I, R, V;
       while(1) {printf("Enter your V(v)\n");
        ask_float_number(&V);
        if(V>0)
        break;printf("V must be greater than 0\n");
    }
        while(1){
            printf("Enter your R(ohms)\n");
            ask_float_number(&R);
            if(R>0) break;
        printf("Resistance must be greater than 0\n");
        }
        I=V/R;
        printf("Current = V / R = %.2f V / %.2f ohms = %.2f A\n", V, R, I);}
    
        else if(value==3){
            double I, R, V;
       while(1) {printf("Enter your V(v)\n");
        ask_float_number(&V);
        if(V>0)
        break;
    printf("V must be greater than 0\n");}
        while(1){
            printf("Enter your I(A)\n");
            ask_float_number(&I);
            if(I>0) break;
            printf("Current must be greater than 0\n"); }
        }
        else{return;}
}
static void Resistance_network(void){
    printf("\n---Calculation total of R ---\n");
    printf("Up to two decimal places\n");
    printf("Select your resistor connection type\n 1. Series\n 2.Paraller\n 3.Return to the Main Menu or go back to Menu item5\n ");
    
    int value=getrightinputvalue_for_menu5_item2();

    if(value==1){
        double R1, R2, Rtotal;
        while(1){
            printf("Please enter R1 in Ohms\n");
            ask_float_number(&R1);
            if(R1>0) break;
            printf("Resistance must be greater than 0\n");
        }
        while(1){
            printf("Please enter R2 in Ohms\n");
            ask_float_number(&R2);
            if(R2>0) break;
            printf("Resistance must be greater than 0\n");
        }
        Rtotal=R1+R2;
        printf("Rtotal = R1 + R2 = %.2f ohms + %.2f ohms = %.2f ohms\n", R1, R2, Rtotal);
    }
    else if(value==2){
        double R1, R2, Rtotal;
        while(1){
            printf("Please enter R1 in Ohms\n");
            ask_float_number(&R1);
            if(R1>0) break;
            printf("Resistance must be greater than 0\n");
        }
        while(1){
            printf("Please enter R2 in Ohms\n");
            ask_float_number(&R2);
            if(R2>0) break;
            printf("Resistance must be greater than 0\n");
        }
        Rtotal=(R1 * R2) / (R1 + R2);
        printf("Rtotal = (R1 * R2) / (R1 + R2) = %.2f ohms\n", Rtotal);
    }
    else{
        return; 
    }
}
static void voltage_divider(void){
    printf("\n---Calculation voltage_divider ---\n");
    printf("Up to two decimal places\n");
    
    double R1, R2, Vin, Vout;

    while(1){
        printf("Please enter R1 in Ohms\n ");
        ask_float_number(&R1);
        if(R1>0) break;
        printf("Resistance must be greater than 0\n");
    }
    
    while(1){
        printf("Please enter R2 in Ohms\n ");
        ask_float_number(&R2);
        if(R2>0) break;
        printf("Resistance must be greater than 0\n");
    }

    while(1){
        printf("Please enter Vin in v\n ");
        ask_float_number(&Vin);
        if(Vin>0) break;
        printf("Voltage must be greater than 0\n");
    }

    Vout = Vin * R2 / (R1 + R2);
    printf("Vout = V * R2 / (R1 + R2) = %.2f V * %.2f / (%.2f + %.2f) = %.2f V\n",
       Vin, R2, R1, R2, Vout);
}

void menu_item_1(void) {
    int value = 0; 
    int exit_value=0;


    do {printf("\n--- Menu 1: Theory Helper ---\n");
        printf("Which point do you want to choose?\n");
        printf("  1.  Ohm's Law\n");
        printf("  2. Series/Parallel resistance\n");
        printf("  3.  Voltage Divider\n");
        printf("  4. Back to main\n");
        value = getrightinputvalue();
        switch (value) {
            case 1: 
                explain_ohms_law(); 
                exit_value = back_mainormenu();
                break; 
            case 2: 
                explain_series_parallel(); 
                exit_value = back_mainormenu();
                break; 
            case 3: 
                explain_voltage_divider(); 
                exit_value = back_mainormenu();
                break;
            case 4:
                printf("Returning to main menu\n"); 
                break;     
            default:
             printf("Invalid selection.\n");
                break;  }             
if (exit_value == 1) {

            break; 
        }
    } while (value != 4); 
}
void menu_item_2(void) {
    int score=0;
    int exit_value=0;
    char quizanswer;
    printf("\n--- Menu 2: Quiz about Ohm's law ---\n");
    printf("You will answer two questions about Ohm's law.\n");
    printf("\nQ1: In the V = I * R , what does R represent?\n");
    printf("  a) Voltage \n  b) Current\n  c) Resistance\n d)There are no correct answer\n");
    quizanswer=getanswer();
    if (quizanswer=='c'){
        score++;
        printf("Correct!! R represents Resistance.\n");    
    }
    else {printf("Your answer is wrong,you shuold review the Ohm's law\n");
        printf("V repersents Voltage\n I repersents Current\n R repersents Resistance\n" );
         }
    printf("\nQ2: If V = 2 V and R = 2 ohms, what is the current?\n");
    printf("  a) 1A \n  b) 1ohms\n  c) 0.5A\n  d) 1V\n");
    quizanswer=getanswer();
    if(quizanswer=='a'){
        score++;
        printf("Correct!!! using Ohms's law I=V/R\n");
    }
    else{printf("your answer is wrong/n");
    printf("Your answer is wrong,you shuold review the Ohm's law\n");}
    printf("\nYou get %d / 2\n", score);
    if(score==2){
        printf("Well done! You may proceed to the next section.\n");}
        else if(score==1){
            printf("Not quite fluent yet — it's recommended to review it again.\n");
            }
            else{
            printf("You haven't mastered it yet — return to review the basic concepts.\n");}
            exit_value=back_mainordoquziagain();
            if (exit_value==1){return;}
            else {menu_item_2();}

        
}

void menu_item_3(void){
    int score=0;
    int exit_value=0;
    char quizanswer;
    printf("\n--- Menu 3: Quiz about series and parallel resistors ---\n");
    printf("You will answer two questions about resistors in series and in parallel.\n");
    printf("\nQ1: Two resistors of 5 ohms and 10 ohms are connected in series.\n");
    printf("What is the total resistance?\n");
    printf("  a) 15ohms \n  b) 20ohms\n  c) 30ohms\n d)There are no correct answer\n");
    quizanswer=getanswer();
        if (quizanswer == 'a') {
        score++;
        printf("Correct!! The total resistance in series is the sum of the resistors.\n");
    } else {
        printf("Your answer is wrong, you should review the series resistance rule.\n");
        printf("In series, the total resistance is the sum of all resistors.\n");
    }
    printf("\nQ2: Two resistors of 5 ohms and 5 ohms are connected in parallel.\n");
    printf("What is the total resistance?\n");
    printf("  a) 15ohms \n  b) 2.5ohms\n  c) 10ohms\n d)There are no correct answer\n");

    quizanswer = getanswer();
    if (quizanswer == 'b') {
        score++;
        printf("Correct!!!\n");
        printf("If two resistors with the same resistance are connected in parallel, the total resistance is half of a single resistor.\n");
    } else {
        printf("Your answer is wrong, you should review the parallel resistance rule.\n");
    }
    printf("\nYou get %d / 2\n", score);
    if (score == 2) {
        printf("Well done! You may proceed to the next section.\n");
    } else if (score == 1) {
        printf("Not quite fluent yet - it's recommended to review it again.\n");
    } else {
        printf("You haven't mastered it yet - return to review the basic concepts.\n");
    }
                exit_value=back_mainordoquziagain();
            if (exit_value==1){return;}
            else {menu_item_3();}
}

void menu_item_4(void) {
    int score = 0;
    int exit_value=0;
    char quizanswer;
    printf("\n--- Menu 4: Quiz about voltage dividers ---\n");
    printf("You will answer two questions about voltage division.\n");

    printf("\nQ1: Two equal resistors of 10 kΩ and 10 kΩ are in series across 10 V.\n");
    printf("What is the voltage across the lower 10 kΩ resistor?\n");
    printf("  a) 10 V\n  b) 5 V\n  c) 2 V\n  d) 0 V\n");
    quizanswer = getanswer();
    if (quizanswer == 'b') {
        score++;
        printf("Correct!! With two equal resistors, the voltage is divided equally, so each gets half of the supply voltage.\n");
    } else {
        printf("Your answer is wrong, you should review the voltage divider rule.\n");
        printf("With two equal resistors in series, each resistor has half of the total voltage.\n");
    }
    printf("\nQ2: A 2 kΩ resistor (R1) and a 3 kΩ resistor (R2) are in series across 10 V.\n");
    printf("What is the voltage across R2 (3 kΩ)?\n");
    printf("  a) 4 V\n  b) 6 V\n  c) 3 V\n  d) 5 V\n");
    quizanswer = getanswer();
    if (quizanswer == 'b') {
        score++;
        printf("Correct!!! In a voltage divider, the voltage across R2 is Vin * R2 / (R1 + R2).\n");
    } else {
        printf("Your answer is wrong, you should review the voltage divider formula Vin * R2 / (R1 + R2).\n");
    }
    printf("\nYou get %d / 2\n", score);
    if (score == 2) {
        printf("Well done! You may proceed to the next section.\n");
    } else if (score == 1) {
        printf("Not quite fluent yet - it's recommended to review it again.\n");
    } else {
        printf("You haven't mastered it yet - return to review the basic concepts.\n");
    }
                exit_value=back_mainordoquziagain();
            if (exit_value==1){return;}
            else {menu_item_4();}
}
void menu_item_5(void) {
    int choice_value = 0; 
    int exit_value=0;
    do {
    printf("\n--- Menu 5: Circuit Calculation Tools ---\n");
    printf("Please select a calculator type:\n");
    printf("  1. Ohm's Law Calculator \n");
    printf("  2. Series/Parallel Resistance Calculator \n");
    printf("  3. Voltage Divider Calculator\n");
    printf("  4. Return to Main Menu\n");
    choice_value= get_user_input_menu_5();
        switch (choice_value) {
            case 1: 
                ohms_law_Calculation();
                exit_value = back_mainormenu();
                
                break; 
            case 2: 
                Resistance_network();
                exit_value = back_mainormenu();
                
                break; 
            case 3: 
                voltage_divider(); 
                exit_value = back_mainormenu();
                break; 
            case 4:
                printf("Returning to main menu...\n"); 
         
                break;     
            default:
             
                printf("Invalid selection.\n");
                break; 
        }


        if (exit_value == 1) {
            break; }
        } while (choice_value != 4); 
    }
