//
//  main.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include <iostream>
#include "src/LinkedList.hpp"
#include "src/ArrayList.hpp"

using namespace std;

void testTriBulleLinkedList()
{
    cout << "Test de Tri Bulle: Linked List" << endl
         << endl;
    LinkedList* l = new LinkedList();
    float f;
    for (int i = 0; i < 5; ++i) {
        cin >> f;
        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    l->triBulle();
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
		delete l;
}

void testTriBulleArrayList()
{
    cout << "Test de Tri Bulle: Array List" << endl
         << endl;
    ArrayList* l = new ArrayList(20);
    float f;
    for (int i = 0; i < 5; ++i) {
        cin >> f;
        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    l->triBulle();
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
		delete l;
}

void testTriMinMaxArrayList()
{
    cout << "Test de Tri Min Max: Array List" << endl
         << endl;
    ArrayList* l = new ArrayList(20);
    float f;
    for (int i = 0; i < 5; ++i) {
        cin >> f;
        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    l->triMinMax();
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
		delete l;
}

void testTriInsertionArrayList()
{
    cout << "Test de Tri Insertion: Array List" << endl
         << endl;
    ArrayList* l = new ArrayList(20);
    float f;
    for (int i = 0; i < 5; ++i) {
        cin >> f;
        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    l->triInsertion();
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
}

void testTriRapideArrayList()
{
    cout << "Test de Tri Rapide: Array List" << endl
         << endl;
    ArrayList* l = new ArrayList(20);
    //    float f;
    for (int i = 0; i < 20; ++i) {
        l->add(rand() % 100 + 1);
        //        cin >> f;
        //        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    l->triRapide();
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
}

void testTriRapideLinkedList()
{
    cout << "Test de Tri Rapide: Linked List" << endl
         << endl;
    LinkedList* l = new LinkedList();
    //    float f;
    for (int i = 0; i < 15; ++i) {
        l->add(rand() % 100 + 1);
        //        cin >> f;
        //        l->add(f);
    }
    for (int i = 0; i < l->size(); ++i)
        cout << l->get(i) << " ";
    cout << endl;
    //    l->triRapide();
    //    for (int i = 0; i < l->size(); ++i)
    //        cout << l->get(i) << " ";
    //    cout << endl;
		delete l;
}

int main()
{
    testTriMinMaxArrayList();
    testTriInsertionArrayList();
}
