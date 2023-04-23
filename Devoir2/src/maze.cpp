
#include "maze.h"
#include <iostream>
using namespace maze;
using namespace mazeNode;
using namespace std;


Maze::Maze(const char ascii[16][16], startPoint point)
{
   // créer les noeuds en fonction du caractère
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         if (ascii[i][j] == 'w')
            this->nodes[i][j] = new mazeNode::NodeWall();
         else if (ascii[i][j] == ' ')
            this->nodes[i][j] = new mazeNode::NodeFree();
         else if (ascii[i][j] == 'c')
            this->nodes[i][j] = new mazeNode::NodeCheese();
      }
   }
   // créer les liens entres voisins
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         if (i > 1)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Up, this->nodes[i + 1][j]);
         if (i < 15)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Down, this->nodes[i - 1][j]);
         if (j > 1)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Left, this->nodes[i][j - 1]);
         if (j < 15)
            this->nodes[i][j]->setNeighbor(mazeNode::NodeNeighbor_Right, this->nodes[i][j + 1]);
      }
   }
   // point de départ
   this->nodes[point.line][point.col]->setVisited();
   this->starter = this->nodes[point.line][point.col];
}

Maze::~Maze()
{
   // peut-être des choses à supprimer
}

bool Maze::checkConsistency()
{
   // tous les noeuds sont instanciés
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         // si le noeud a un type eNodeType   NodeType_Wall ou NodeType_Free ou NodeType_Cheese
         if ((this->nodes[i][j]->getType() != mazeNode::NodeType_Wall) && (this->nodes[i][j]->getType() != mazeNode::NodeType_Free) && (this->nodes[i][j]->getType() != mazeNode::NodeType_Cheese))
            return false;
      }
   }
   // point de départ valide

   return true;
}

bool Maze::solve()
{
   return this->parse(this->starter);
}

void Maze::getAsciiFormat(char ascii[16][16])
{
   for (int i = 0; i < 16; i++)
   {
      for (int j = 0; j < 16; j++)
      {
         ascii[i][j] = this->nodes[i][j]->getString();
      }
   }
}

bool Maze::parse(mazeNode::Node *node)
{
   // la récursivité peut-être intéressante pour le parcours d'un arbre de noeuds
   // On va examiner tous les voisins du noeud

   for (int i = NodeNeighbor_Up; i <= NodeNeighbor_Right; i++)
   {
      eNodeNeighbor neighbor = static_cast<eNodeNeighbor>(i);
      cout  << (node->getNeighbor(neighbor))->getString() << endl;
      /*
      if (node->getNeighbor(neighbor)->getType() == mazeNode::NodeType_Cheese)
      {
         return true;
      }
      
      else if (node->getNeighbor(neighbor)->getType() == mazeNode::NodeType_Free)
      {
         if (!node->getNeighbor(neighbor)->isVisited())
            return parse(node->getNeighbor(neighbor));
      }
      */
   }

   return true;
}
