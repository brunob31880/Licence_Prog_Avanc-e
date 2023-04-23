
#include "node.h"
#include <iostream>

using namespace mazeNode;

Node::Node()
{
   // par défaut les voisins sont nulls et le type du noeud NodeType_Wall
   setNeighbor(NodeNeighbor_Up, NULL);
   setNeighbor(NodeNeighbor_Down, NULL);
   setNeighbor(NodeNeighbor_Left, NULL);
   setNeighbor(NodeNeighbor_Right, NULL);
   // par defaut il n'est pas visité
   this->visited = false;
}

Node::~Node()
{
}

eNodeType Node::getType()
{
   // retourne le type de noeud
   return this->type;
}

void Node::setNeighbor(eNodeNeighbor position, Node *neighbor)
{
   if (position == NodeNeighbor_Up)
      this->up = neighbor;
   else if (position == NodeNeighbor_Down)
      this->down = neighbor;
   else if (position == NodeNeighbor_Left)
      this->left = neighbor;
   else if (position == NodeNeighbor_Right)
      this->right = neighbor;
}

Node *Node::getNeighbor(eNodeNeighbor position)
{
   if (position == NodeNeighbor_Up)
      return this->up;
   else if (position == NodeNeighbor_Down)
      return this->down;
   else if (position == NodeNeighbor_Left)
      return this->left;
   else if (position == NodeNeighbor_Right)
      return this->right;
   else
   {
      std::cout << "Error in Node::getNeighbor(eNodeNeighbor position)" << std::endl;
      return NULL;
   }
}

bool Node::isNeighborFree(eNodeNeighbor position)
{
   // Est-ce que le voisin à la position donnée existe et peut-être visité ?
   if (position == NodeNeighbor_Up)
   {
      if (this->up != NULL)
         return this->up->isFreeToVisit();
      else
         return false;
   }
   else if (position == NodeNeighbor_Down)
   {
      if (this->down != NULL)
         return this->down->isFreeToVisit();
      else
         return false;
   }
   else if (position == NodeNeighbor_Left)
   {
      if (this->left != NULL)
         return this->left->isFreeToVisit();
      else
         return false;
   }
   else if (position == NodeNeighbor_Right)
   {
      if (this->right != NULL)
         return this->right->isFreeToVisit();
      else
         return false;
   }
   else
      return false;
}

void Node::setVisited()
{
   this->visited = true;
}

bool Node::isVisited()
{
   return this->visited;
}

bool Node::isFreeToVisit()
{
   // on ne peut pas visiter un mur 
   if (this->getType() == NodeType_Wall) return false;
   // noeud de type passage 
   else if (this->getType()== NodeType_Free) return !this->visited;
   // fromage
   else return true;
}

NodeWall::NodeWall() : Node()
{
   this->type = NodeType_Wall;
}

const char NodeWall::getString()
{
   return 'w';
}

NodeFree::NodeFree() : Node()
{
   this->type = NodeType_Free;
}

const char NodeFree::getString()
{
   if (this->visited)
      return '.';

   return ' ';
}

NodeCheese::NodeCheese() : Node()
{
   this->type = NodeType_Cheese;
}

const char NodeCheese::getString()
{
   if (this->visited)
      return 'X';

   return 'c';
}
