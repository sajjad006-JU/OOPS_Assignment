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
                printf("Item Code: %d, avialable qty: %d, rate: %d\n", code, items[k].getAvailableQty(), items[k].getRate());
            }
        }
};

int main () {
    ItemList items;
    items.addItem(1, "phone", 21, 23);
    items.displayItemDetail(1);
    items.issueItem(2, 21);
    items.issueItem(1, 45);
    items.issueItem(1, 1);
    items.displayItemDetail(1);
}