// created by <kaveendrankavee@gmail.com> No commits final 14:14 DEC 24 2023
#include <iostream>

int already_avil_books = 10;


using namespace std;
// data base for books as a structure data type
struct bookDb{
    int bookID;
    string bookName;
    string bookAut;
    int bookPrice;
};


struct buyBook{
    string bookName;
    int bookPrice;
    int qty;
};



void bookManagement(bookDb x[]); 
int main();




// function for Welcome screen

void Welcome() {

    cout <<" _____ _____ _____ _____ _____ _____\n";
    cout <<"|   | |   __|_   _|  |  | __  |  _  |\n";
    cout <<"| | | |   __| | | |     |    -|     |\n";
    cout <<"|_|___|_____| |_| |__|__|__|__|__|__|\n\n";
    cout <<"=============== BOOK SHOP ===========";
    cout <<"                  Kandy" ;
    cout <<"                 V 0.01 \n \n";

    // employee credintial

    string cred_name ="user";
    int cred_pin = 2002;

    string usr_name;
    int pin_num;
    cout <<"-----------Employee LOGIN-----------\n";
    
    cout <<"  Enter Name :";
    cin >> usr_name;

    cout <<"  Enter PIN  :";
    cin >> pin_num;
    // check login successfull or not
    
    while(usr_name != cred_name && pin_num != cred_pin){
        cout <<"  --Error Try agian--\n";
        
        cout <<"  Enter Name :";
        cin >> usr_name;
        
        cout <<"  Enter PIN  :";
        cin >> pin_num;
    }

    // successfull login

    cout << "\n------------Login Successfull-----------\n" << "           Welcome           "<<usr_name<<"!\n\n\n\n";

}

// acting static data base for books

void viewBook(bookDb x[]){

    cout << "\n"<<"------BOOKS DIRECTORY------\n\n";
    
    // print out all the data of books
    cout << "     |ID|" << "|Name|" << "|Auther|" << "|Price|" <<"\n\n";

    for(int i=0;i<=already_avil_books;i +=1){
        
        cout << "   |"<< x[i].bookID <<"|"<<"|"<< x[i].bookName <<"|" <<x[i].bookAut <<"|"<<x[i].bookPrice <<"Rs|"<<"\n";
    }
    int inp;
    cout << "   For previous menu|1| :";   
    cin >> inp;
    if(inp == 1){
        bookManagement(x);
    }
}

// add books to  data base
void addBook(bookDb x[]){
    cout << "\n";
    cout << "------ADD BOOKS TO DATA BASE------\n";
    int stat=0;

    for(already_avil_books;already_avil_books <=10000;already_avil_books +=1){
        int id;                
        cout <<"  ID-----:";
        cin >> id;
        if(id==0){
            break;
        }
        cout <<"  Name---:";
        cin >> x[already_avil_books].bookName;
        cout <<"  Auther-:";
        cin >> x[already_avil_books].bookAut;
        cout <<"  Price--:";
        cin >> x[already_avil_books].bookPrice;
        cout << "  Book succesfully added\n\n";
               
    }
    int inp;
    cout << "  For previous menu|1| exit|0|\n";
    
    cout << "  Input--------------:";
    cin >> inp;
    if(inp == 1){
        bookManagement(x);
    }else{
        main();
    }
}


// book search function

void searchBook(bookDb x[]) {
    string searchQuery;
    cout << "Enter book name, author, or ID to search: ";
    cin.ignore(); // Clear input buffer
    getline(cin, searchQuery);

    bool found = false;
    cout << "Search Results:\n";
    cout << "|ID|" << "|Name|" << "|Author|" << "|Price|" << "\n";

    for (int i = 0; i < already_avil_books; ++i) {
        if (x[i].bookName == searchQuery || x[i].bookAut == searchQuery || to_string(x[i].bookID) == searchQuery) {
            cout << "|" << x[i].bookID << "|" << x[i].bookName << "|" << x[i].bookAut << "|" << x[i].bookPrice << "Rs|\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    int inp;
    cout << "For previous menu|1| Exit|0| :";
    
    cin >> inp;
    if (inp == 1) {
        bookManagement(x);
    }else{
        main();
    }
}



int bookOrder(bookDb x[]) {
    cout << "--BOOKS DIRECTORY--\n";
    cout << "|ID|" << "|Name|" << "|Author|" << "|Price|" << "\n";

    for (int i = 0; i < already_avil_books; i++) {
        cout << "|" << x[i].bookID << "|" << x[i].bookName << "|" << x[i].bookAut << "|" << x[i].bookPrice << "Rs|\n";
    }

    struct Quotation {
        int id;
        int price;
        int qty;
    };

    Quotation items[100];
    int numItems = 0;
    int totalPrice = 0;

    while (true) {
        int selectedID, quantity;
        cout << "Select book ID to purchase (0 to finish): ";
        cin >> selectedID;

        if (selectedID == 0) {
            break;
        }

        bool found = false;
        for (int i = 0; i < already_avil_books; i++) {
            if (x[i].bookID == selectedID) {
                found = true;
                cout << "Enter quantity for " << x[i].bookName << ": ";
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "Invalid quantity. Please enter a valid quantity.\n";
                    continue;
                }

                items[numItems].id = selectedID;
                items[numItems].price = x[i].bookPrice;
                items[numItems].qty = quantity;

                totalPrice += (x[i].bookPrice * quantity);
                numItems++;
                break;
            }
        }

        if (!found) {
            cout << "Book ID not found. Please enter a valid book ID.\n";
        }
    }

    // Displaying the selected items and total price
    cout << "\nSelected Items:\n";
    cout << "|ID|" << "|Price|" << "|Qty|" << "\n";
    for (int i = 0; i < numItems; i++) {
        cout << "|" << items[i].id << "|" << items[i].price << "Rs|" << items[i].qty << "|\n";
    }

    cout << "Total Price: " << totalPrice << "Rs\n";

    int inp;
    cout << "For previous menu|1| Exit|0|\n";
    cin >> inp;
    if (inp == 1) {
        bookManagement(x);
    }else{
        main();
    }

    cout << totalPrice;
    return totalPrice;
}




// function for Book Management
void bookManagement(bookDb x[]){
    int input;
    cout << "------------BOOK MANAGEMENT------------\n\n";
    cout << "------Select Option------\n";
    cout << "   View Books-----|1|\n";
    cout << "   Add book-------|2|\n";
    cout << "   Book Search----|3|\n";
    cout << "   Book Orders----|4|\n";   
    cout << "   LOGOUT---------|0|\n";
    cout << "   INPUT--------- :";
    cin >> input;
    

    switch(input){
        case 1:
            cout <<"\n\n";
            viewBook(x);
            break;
        case 2:
            addBook(x);
            break;

        case 3:
            searchBook(x);
            break;

        case 4:
            bookOrder(x);
            break;

        case 0:
            main();
            break;

    }
}

int main(){
    // adding initial data to books programmatically
    bookDb books[10000];
    books[0] ={2010,"rand1","kaveendran",200};
    books[1] ={2011,"rand2","kaveendran",200};
    books[2] ={2012,"rand3","kaveendran",200};
    books[3] ={2013,"rand4","kaveendran",200};
    books[4] ={2014,"rand5","kaveendran",200};
    books[5] ={2015,"rand6","kaveendran",200};
    books[6] ={2016,"rand7","kaveendran",200};
    books[7] ={2017,"rand8","kaveendran",200};
    books[8] ={2018,"rand9","kaveendran",200};
    books[9] ={2019,"rand10","kaveendran",200};

    Welcome(); 
    bookManagement(books);
   
}


