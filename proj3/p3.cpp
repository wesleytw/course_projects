#include <iostream>
using namespace std;

typedef struct Node
{
  int data = -1;
  Node *left = NULL, *right = NULL;
} Node;

Node *newNode(int data);
void printPreorder(Node *node);

int main()
{
  string input;
  int star_summon = 0, sum_attack = 0;
  Node *root = new Node;
  int *i = NULL;

  while (true)
  {
    cin >> input;
    if (input == "Summon")
    {
      cin >> input; // ->
      cin >> input; // 4*
      star_summon = stoi(input.substr(0, 1));

      // Monster with Star Points <= 4: Ricky can summon the monster without sacrifice any monster.
      if (star_summon <= 4)
      {
        if (!root->left)
        {
          root->left = newNode(star_summon);
        }
        else if (!root->right)
        {
          root->right = newNode(star_summon);
        }
        else if (root->left && root->right)
        {
          // if (root->left->data > star_summon && root->right->data > star_summon)
          //   continue;;
          Node *sacrifice;
          if (root->left->data <= root->right->data)
          {
            sacrifice = root->left;
            root->left = newNode(star_summon);
            root->left->left = sacrifice;
          }
          else
          {
            sacrifice = root->right;
            root->right = newNode(star_summon);
            root->right->right = sacrifice;
          }
        }
      }
      // 5 <= Monster with Star Points <= 6: Ricky need to acrifice one monster to summon this monster.
      else if (star_summon >= 5 && star_summon <= 6)
      {
        Node *sacrifice;
        if (root->left && root->right)
        {
          if (root->left->data <= root->right->data)
          {
            sacrifice = root->left;
            root->left = newNode(star_summon);
            root->left->left = sacrifice;
          }
          else
          {
            sacrifice = root->right;
            root->right = newNode(star_summon);
            root->right->right = sacrifice;
          }
        }
        else if (!root->left)
        {
          sacrifice = root->right;
          root->right = newNode(star_summon);
          root->right->right = sacrifice;
        }
        else if (!root->right)
        {
          sacrifice = root->left;
          root->left = newNode(star_summon);
          root->left->left = sacrifice;
        }
      }
      // 7 <= Monster with Star Points <= 8: Ricky need to sacrifice two monsters to summon this monster.
      else if (star_summon >= 7 && star_summon <= 8)
      {
        Node sacrifice;
        sacrifice = *root;
        root->left = newNode(star_summon);
        root->left->left = sacrifice.left;
        root->left->right = sacrifice.right;
        root->right = NULL;
      }
    }
    else if (input == "Attack")
    {
      if (root->left)
      {
        sum_attack = sum_attack + root->left->data;
      }
      if (root->right)
      {
        sum_attack = sum_attack + root->right->data;
      }

      // cout << endl
      //      << sum_attack << endl;
    }
    else if (input == "TheEnd")
    {
      break;
    }
  }

  printPreorder(root);
  cout << endl
       << sum_attack << endl;

  return 0;
}

Node *newNode(int data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void printPreorder(struct Node *node)
{
  if (node == NULL)
    return;
  if (node->data > 0)
    cout << node->data << "* ";

  printPreorder(node->left);

  printPreorder(node->right);
}
/*
Summon -> 1*
Attack
Summon -> 4*
Summon -> 4*
Summon -> 5*
Attack
Summon -> 6*
Attack
Summon -> 6*
Attack
Summon -> 8*
Attack
Summon -> 5*
Attack
Summon -> 1*
Attack
Summon -> 5*
Attack
TheEnd
*/
/*
Summon -> 1*
Attack
Summon -> 4*
Summon -> 8*
Attack
Summon -> 1*
Attack
Summon -> 1*
Attack
Summon -> 1*
Attack
TheEnd
*/
/*
Summon -> 1*
Attack
Attack
Attack
Summon -> 4*
Summon -> 8*
Attack
Attack
Attack
Summon -> 1*
Attack
Summon -> 1*
Attack
TheEnd
*/
/*
Summon -> 4*
Summon -> 4*
Summon -> 3*
Summon -> 5*
Attack
Summon -> 8*
Summon -> 4*
Attack
Attack
TheEnd
*/