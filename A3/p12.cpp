/*
Design the class(es) for the following scenario:
1. An item list contains item code, name, rate, and quantity for several items.
2. Whenever a new item is added in the list uniqueness of item code is to be checked.
3. Time to time rate of the items may change.
4. Whenever an item is issued or received existence of the item is checked and quantity is updated.
5. In case of issue, availability of quantity is also to be checked.
6. User may also like to know price/quantity available for an item.
*/
#include <stdio.h>

#define LIST_SIZE 100

class Item {
    private:
        int code;
        char* name;
        int rate;
        int quantity;
        int issued_quantity;

    public:
        Item() {
            code=0;
            name="";
            rate=0;
            quantity=0;
            issued_quantity=0;
        }

        Item(int code, char* name, int rate, int quantity) {
            this->code=code;
            this->name=name;
            this->rate=rate;
            this->quantity=quantity;
            issued_quantity=0;
        }

        void setRate(int rate) {
            this->rate=rate;
        }

        int getCode() {
            return code;
        }

        int getAvailableQty() {
            return quantity-issued_quantity;
        }

        int getRate() {
            return rate;
        }

        void issueItem(int qty) {
            issued_quantity+=qty;
        }

        char* getName() {
            return name;
        }
};

class ItemList {

    private:
        Item items[LIST_SIZE];
        int count;

        int findItem(int code) {
            for (int i=0; i<LIST_SIZE; i++) {
                if (items[i].getCode()==code)
                    return i;
            }
            return -1;
        }

    public:
        ItemList() {
            count=0;
        }

        void addItem(int code, char* name, int rate, int quantity) {
            if (findItem(code)==-1) {
                Item item(code, name, rate, quantity);
                items[count]=item;
                count++;
            } else {
                printf("Item code must be unique!\n");
            }
        }

        void issueItem(int code, int qty) {
            int k=findItem(code);
            int availableQty=items[k].getAvailableQty();

            if (k!=-1) {
                if (availableQty>=qty) {
                    printf("Item issued!");
                    items[k].issueItem(qty);
                } else {
                    printf("Insufficient quantity!\n");
                }
            } else {
                printf("Unavailable item!\n");
            }
        }

        void displayItemDetail(int code) {
            int k=findItem(code);
            if (k!=-1) {
                printf("Item Code: %d, Item name: %s, available qty: %d, rate: %d\n", code, items[k].getName(), items[k].getAvailableQty(), items[k].getRate());
            } else {
                printf("Unavailable item!\n");
            }
        }
};

int main () {
    ItemList items;

    while (true) {
        int option;
        printf("\n1. Add Item\t2. Issue Item\t3. Display Item Detail\t4. Exit\n");
        scanf("%d", &option);

        // use switch case to perform operations based on user input
        switch (option) {
            case 1: {
                int code, rate, quantity;
                char name[50];
                printf("Enter item code, name, rate and quantity: ");
                scanf("%d %s %d %d", &code, name, &rate, &quantity);
                items.addItem(code, name, rate, quantity);
                break;
            }
            case 2: {
                int code, qty;
                printf("Enter item code and quantity to issue: ");
                scanf("%d %d", &code, &qty);
                items.issueItem(code, qty);
                break;
            }
            case 3: {
                int code;
                printf("Enter item code to display details: ");
                scanf("%d", &code);
                items.displayItemDetail(code);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}