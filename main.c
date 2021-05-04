#include <stdio.h>
#include <stdlib.h>

struct Wallet {
    float amount;
    float balance;
} ferrisWallet;

void loadDoges() {
    char doges[1000];
    FILE *fptr;
    fptr = fopen("/home/kleierferris/CLionProjects/dogecoin/dogewallet.dat", "r");
    fscanf(fptr, "%s", doges);
    fclose(fptr);
    ferrisWallet.amount = atof(doges);
}

void ignoreRestOfLine(FILE *fp) {
    int c;
    while ((c = fgetc(fp)) != EOF && c != '\n');
}

int ask() {
    int que;
    printf("\n[1] Again\n"
           "[2] Back to main menu\n"
           "[3] Exit program\n");
    INPUT2:
    printf(">> ");
    scanf("%d", &que);
    if (que == 1 || que == 2 || que == 3) {
        goto OEK2;
    } else {
        ignoreRestOfLine(stdin);
        printf("Enter a valid option\n");
        goto INPUT2;
    }

    OEK2:
    switch (que) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Please enter a valid option");
    }
}

int calculator() {

    loadDoges();
    char priceInput[20] = "";
    DSE:
    printf("\nCurrent Doge price in EUR\n");
    NARDF:
    printf(">> ");
    scanf("%s", priceInput);
    float price = atof(priceInput);

    if (price > 0) {
        ferrisWallet.balance = ferrisWallet.amount * price;
    } else {
        printf("\nPlease enter correct amount\n");
        goto NARDF;
    }
    printf("\nConversion:\n   DOGE %.2f\n   EUR  %.2f\n", ferrisWallet.amount, ferrisWallet.balance);
    int result = ask();
    if (result == 1) {
        goto DSE;
    } else {
        return result;
    }
}

int addresses() {
    UDK:
    printf("\nYour Addresses:\n");
    printf("  D8A2cEBVDe2rowwH3N5qJ3Us5Q3D5SdGqV\n"
           "  DEJihdhBY2B96kVTXFtaMQQPVRuyMHv3RS\n"
           "  DQUKUjRidNQax9DFm7VRmc5oFMKeDj2x48\n"
           "  DR7Pk2FgisstezQAWLcJL3cKjgGTJ6B7Y5\n"
           "Paper Wallet:\n"
           "  DELVDMxNcZFPQUqcxw8rvQ6ZoanCAJsL3V\n");
    int result = ask();
    if (result == 1) {
        goto UDK;
    } else {
        return result;
    }
}

int update() {

    loadDoges();
    DSE:
    printf("\nYou are currently hodling DOGE%.2f", ferrisWallet.amount);
    printf("\nDo you want to update Dogecoins?\n  [1] Yes\n  [2] No\n");

    int choice;
    INPUT:
    printf(">> ");
    scanf("%d", &choice);
    if (choice == 1 || choice == 2) {
        ignoreRestOfLine(stdin);
        goto OEK;
    } else {
        ignoreRestOfLine(stdin);
        printf("Enter a valid option\n");
        goto INPUT;
    }

    OEK:
    switch (choice) {
        case 1:
            goto YOP;
        case 2:
            goto OFP;
        default:
            printf("Please enter a valid option");
    }

    YOP:
    printf("");
    char dogeinput[20];
    FILE *fp;
    fp = fopen("/home/kleierferris/CLionProjects/dogecoin/dogewallet.dat", "w");
    printf("\nYour new Doge Amount\n>> ");
    scanf("%s", dogeinput);
    fprintf(fp, dogeinput);
    fclose(fp);

    OFP:
    printf("");
    int result = ask();
    if (result == 1) {
        goto DSE;
    } else {
        return result;
    }
}


void hello() {
    loadDoges();
    printf("\nHello, you are currently hodling DOGE%.2f\n", ferrisWallet.amount);
    YER:
    printf("\nWhat do you want to do?\n"
           "  [1] Calculate Balance\n"
           "  [2] Update Doge Amount\n"
           "  [3] See Wallet Addresses\n");

    int choice;
    int result;

    INPUT:
    printf(">> ");
    scanf("%d", &choice);
    if (choice == 1 || choice == 2 || choice == 3)
        goto OEK;
    else
        ignoreRestOfLine(stdin);
    printf("Enter a valid option\n");
    goto INPUT;


    OEK:
    switch (choice) {
        case 1:
            result = calculator();
            break;
        case 2:
            result = update();
            break;
        case 3:
            result = addresses();
            break;
        default:
            printf("Please enter a valid option");
    }

    if (result == 2)
        goto YER;
}

int main() {

    hello(); // Startup Message
}
