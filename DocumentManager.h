#include <iostream>
#include <unordered_map>
#include <unordered_set>

class DocumentManager{
    private:
        struct Document{
            Document(std::string name, int id, int license_limit);

            std::string name;
            int id;
            int license_limit;
            int current_copies_borrowed;
        }

        std::unordered_map<int, Document> documents;
        std::unordered_set<int> patrons;
        std::unordered_map<std::string, int> name_to_docid;

    public:
        void addDocument(std::string name, int id, int license_limit);
        void addPatron(int patronID);
        int search(std::string name);
        bool borrowDocument(int docid, int patronID);
        void returnDocument(int docid, int patronID);
};