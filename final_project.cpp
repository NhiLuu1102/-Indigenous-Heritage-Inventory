#include<iostream>
using namespace std;

class HeritageSite{
private:
    double siteID;
    string name;
    string location;
    double categoryID;
public:
//constructor to initiallized the attributes
//default constructor
    HeritageSite(double id = 0, string name1 = "Unknown", string location1 = "Unknown", double cate = 0){
        siteID = id;
        name = name1;
        location = location1;
        categoryID = cate;
    }
    void viewSiteDetails(){
        cout<<"Details of the heritage site: " << endl;
        cout<<"Site ID: " <<siteID<<endl;
        cout<<"Name: " <<name<<endl;
        cout<<"Location: " <<location<<endl;
        cout<<"Category: " <<categoryID<<endl;
    }
    //setter method 
    void updateProfiles(string newName, string newLocation, double newID, double newCate){
        name = newName;
        location = newLocation;
        categoryID = newCate;
        siteID = newID;        
        cout <<"Site details updated successfully!" <<endl;
    }
    //getter method 
    string getName(){
        return name;
    }
    string getLocation(){
        return location;
    }
    double getID(){
        return siteID;
    }
    double getCateID(){
        return categoryID;
    }
    //operator overloading for ==
    bool operator==(HeritageSite &other){ //if the 2 heritage objects are equal => true, else fale
        return siteID == other.siteID; //compare siteID
    } 
    virtual void getDescription() {
        cout << "Heritage Site Description: " << endl;
    }
};

//derived from heritage site
class CulturalSite : public HeritageSite {
private:
    string culturalSignificance;
public:
//constructor to initiallized the attributes
    CulturalSite(double id, string name1, string location1, double cate, string culSig) 
    : HeritageSite(id, name1, location1, cate), culturalSignificance(culSig) {}
    void getDescription()override{
        cout << "Cultural Site Description: " << culturalSignificance << endl;
    }
};

//derived from heritage site
class NaturalSite : public HeritageSite{
private:
    string ecosystemType;
    //constructor to initiallized the attributes
public:
    NaturalSite(double id, string name1, string location1, double cate, string eco): HeritageSite(id, name1, location1, cate){
        ecosystemType=eco; 
    }
    void getDescription() override{
        cout << "Natural Site Description: " << ecosystemType << endl;
    }
};

//category class
class Category{
private:
    double categoryID;
    string categoryName;
    //composition 
    HeritageSite siteList [10]; //fixed size array of heritage list
    int siteCount;

public: 
// Default constructor
    Category() : categoryID(0), categoryName("Unknown"), siteCount(0) {}

// Parameterized constructor
    Category(double id, string name) : categoryID(id), categoryName(name), siteCount(0) {}
//method to add site
    
void addSite(HeritageSite site){
        if (siteCount < 10 ){
            siteList[siteCount] = site; //current index
            siteCount++; //increment for next indexes
            cout<<"Site added to Category successfully."<<endl;
        } else{
            cout<<"Site is not added. Try again. "<<endl;
        }
    }
//void method
    void viewCategoryDetails(){
        cout<<"Category information: " <<endl;
        cout<<"Category ID: " <<categoryID <<endl;
        cout<<"Category Name: " <<categoryName<<endl;
        for(int i = 0; i < siteCount; ++i){
            siteList[i].viewSiteDetails();
        }
    }
};

//preservation
class PreservationEffort{
private: 
    double effortID;
    double siteID;
    string description;
    string date; //yyyy-mm-dd
    //constructor to initiallized the attributes
public:
    PreservationEffort(double eID = 0, double sID = 0, string dscpt = "Unknown", string d  = "Unknown"){
        effortID = eID;
        siteID = sID;
        description = dscpt;
        date = d;
    }
//method:

    void recordEffort(double eID, double sID, string dscpt, string d){
        effortID = eID;
        siteID = sID;
        description = dscpt;
        date = d;
    }

    void viewEffortDetails(){
        cout<<"Preservation effort:" <<endl;
        cout<<"Effort ID: " <<effortID<<endl;
        cout<<"Site ID: " << siteID<<endl;
        cout<<"Description: "<<description <<endl;
        cout<<"Date (YYYY-MM-DD): "<<date<<endl;
    }
};

//heritage
class HeritageInventorySystem {
private: 
//composition
    HeritageSite siteList [10];
    Category cateList[10];
    PreservationEffort effortList[10];
    int siteCount;
    int cateCount;
    int effortCount;
public: 
//constructor to initiallized the attributes
    HeritageInventorySystem() : siteCount(0), cateCount(0), effortCount(0) {}
//method to add site
    void addSite(){ 
        int siteType;
        double id, cateID;
        string name, location;

        cout<<"Enter site type. \nType 1: Cultural Site \nType 2: Natural Site"<<endl;
        cin >> siteType;

        cout<<"Enter site ID: "<<endl;
        cin >> id;
    
        cout <<"Enter name: "<<endl;
        cin >>name;

        cout<<"Enter location: "<<endl;
        cin>>location;

        cout<<"Enter category ID: "<<endl;
        cin>>cateID;

        if (siteType == 1){
            string significance;
            cout<<"Enter cultural significance: "<<endl;
            cin >> significance;
            siteList[siteCount++] = CulturalSite(id, name, location, cateID, significance); // Create and add the object
        
        }else if(siteType == 2){
            string ecosystem;
            cout<<"Enter the ecosystem: "<<endl;
            cin >> ecosystem;
            siteList[siteCount++] = NaturalSite(id, name, location, cateID, ecosystem); //Create and add the object
        }
        cout<<"Site added to Heritage Inventory System successfully."<<endl;
    }       
//method to add cate
    void addCategory(){
        double id2;
        string name2;

        cout<<"Enter category ID: "<<endl;
        cin >> id2;

        cout<<"Enter category name: "<<endl;
        cin >>name2;
        cateList[cateCount++] = Category(id2,name2); //Create and add the object   
        cout<<"The category added to Heritage Inventory System successfully! "<<endl;
    }
    
//method to process preservation efforts
    void processPreservationEfforts(){
        double effortID, siteID;
        string description, date;

        cout<<"Enter effort ID: "<<endl;
        cin >> effortID;
        cout<<"Enter siteID: "<<endl;
        cin >> siteID;
        cout<<"Preservation description: "<<endl;
        cin >> description;
        cout<<"Date (YYYY-MM-DD): "<<endl;
        cin >> date;
        if (effortCount<=10){
            effortList[effortCount++] = PreservationEffort(effortID, siteID, description, date);
            cout << "Preservation effort recorded successfully!" << endl;
        } else {
            cout << "Error: Preservation effort list is full!" << endl;
        }
    }
    void viewPreservationhistory(int preservationid) {
        if (preservationid < 0 || preservationid >= effortCount) {
            cout << "Error: Invalid Preservation ID. Please try again." << endl;
            return;
        }
        effortList[preservationid].viewEffortDetails(); 
    }

    void viewAllSites(){
        for (int i = 0; i < siteCount; ++i) {
            siteList[i].viewSiteDetails();
        }
    }

    // Method to view all categories
    void viewAllCategories(){
        for (int i = 0; i < cateCount; ++i) {
            cateList[i].viewCategoryDetails();
        }
    }
};
int main(){
    HeritageInventorySystem system;
    int choice;
    do{
        cout<<"---Indigenous Heritage Inventory System---"<<endl;
        cout << "1. Register a Heritage Site"<<endl;
        cout << "2. Add a Category"<<endl;
        cout << "3. View Heritage Sites"<<endl;
        cout << "4. Record Preservation Efforts"<<endl;
        cout << "5. View Preservation History"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1){   
            system.addSite();
        } else if(choice == 2){
            system.addCategory(); //add new category
        } else if (choice == 3){
            system.viewAllSites();
        } else if(choice == 4){
            system.processPreservationEfforts(); //record effort
        } else{
            int preservationid;
            cout<<"Enter Preservation ID: "<<endl;
            cin>>preservationid;
            system.viewPreservationhistory(preservationid); //viewing history
        }
    } while (choice !=6);   
            
return 0; 
}