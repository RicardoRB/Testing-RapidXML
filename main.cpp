#include <iostream>
#include <fstream>
#include <vector>
#include <rapidxml.hpp>

using namespace std;
using namespace rapidxml;

int main() {
    ifstream myfile("english.xml");
    xml_document<> doc;
    /* "Read file into vector<char>"  See linked thread above*/
    vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>( ));

    buffer.push_back('\0');

    cout << &buffer[0] << endl;

    doc.parse<0>(&buffer[0]);

    cout << "Name of my first node is: " << doc.first_node()->name() << endl;

    xml_node<> *node = doc.first_node(doc.first_node()->name());
    cout << "Name first subnode of my first node is: " << node->first_node()->name() << endl;
    cout << "Node " << node->first_node()->name() << " has value " << node->first_node()->value() << endl;
    cout << "List of all nodes" << endl;
    for (xml_node<> *child = node->first_node(); child; child = child->next_sibling()) {
        cout << child->name() << endl;
    }
    cout << "List of all attributes of first node" << endl;
    for (xml_attribute<> *attr = node->first_node()->first_attribute(); attr; attr = attr->next_attribute()) {
        cout << "Node foobar has attribute " << attr->name() << " ";
        cout << "with value " << attr->value() << "\n";
    }
    return 0;
}
