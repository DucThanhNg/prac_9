#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class DocumentManager {
private:
    struct Document {
        std::string name;
        int id;
        int license_limit;
        int borrowed_count;

        Document(const std::string& n, int i, int limit)
            : name(n), id(i), license_limit(limit), borrowed_count(0) {}
    };

    std::vector<Document> documents;
    std::unordered_set<int> patrons;
    std::unordered_map<std::string, int> nameToDocId;

public:
    void addDocument(const std::string& name, int id, int license_limit) {
        if (nameToDocId.count(name) == 0) {
            documents.emplace_back(name, id, license_limit);
            nameToDocId[name] = id;
        }
    }

    void addPatron(int patronID) {
        patrons.insert(patronID);
    }

    int search(const std::string& name) {
        if (nameToDocId.count(name) > 0) {
            return nameToDocId[name];
        }
        return 0;
    }

    bool borrowDocument(int docid, int patronID) {
        auto docIt = std::find_if(documents.begin(), documents.end(), [docid](const Document& doc) {
            return doc.id == docid;
        });

        if (docIt != documents.end() && patrons.count(patronID) > 0) {
            Document& doc = *docIt;
            if (doc.borrowed_count < doc.license_limit) {
                doc.borrowed_count++;
                return true;
            }
        }
        return false;
    }

    void returnDocument(int docid, int patronID) {
        auto docIt = std::find_if(documents.begin(), documents.end(), [docid](const Document& doc) {
            return doc.id == docid;
        });

        if (docIt != documents.end()) {
            Document& doc = *docIt;
            if (doc.borrowed_count > 0) {
                doc.borrowed_count--;
            }
        }
    }
};
