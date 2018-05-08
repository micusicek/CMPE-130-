#ifndef LISTNODE_H
#define LISTNODE_H
#include<string>
#include<chrono>
#include<random>
#include<utility>
#include<string>

class ListNode
{
public:
    int room_num;
    double room_price;
public:
    ListNode();
    ListNode(const ListNode &n);
    ListNode &operator = (const ListNode &n);
    void set_room(int roomNum);
    void set_price(double price);
    void set_name(std::string n);
    void set_phone(long int number);
    double price_gen();


};

#endif // LISTNODE_H
