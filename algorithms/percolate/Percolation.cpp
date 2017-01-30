#include "Percolation.hpp"

Percolation::Percolation(unsigned int rows, unsigned int cols):
  fsrows(rows),
  fscols(cols),
  nuOfOpened(0),
  bag(std::queue<std::pair<unsigned int, unsigned int>>()),
  percolated(false)
{
  assert(rows > 0 && cols > 0);
  f = std::vector<std::vector<char>>(rows);
  init();
}

void Percolation::open(unsigned int row, unsigned int col) {
  if (isBlocked(row,col)) {
    f[row][col] = s[1];
    ++nuOfOpened;
    if(row == 0 || has_filled_neighbour(row,col))
      bag.push(std::pair<unsigned int,unsigned int>(row,col));
  } else {
    std::cout << "point ( " << row << ", " << col << " ) is already open. (<row>,<col>)\n";
  }
}

void Percolation::init() {
  for (unsigned int i = 0; i < fsrows; ++i) {
    std::vector<char> fline(fscols);
    for (unsigned int j = 0; j < fscols; ++j)
      fline.at(j) = s[0];
    f.at(i) = fline;
  }
}

std::queue<std::pair<unsigned int,unsigned int>> Percolation::examine_neighbours(unsigned int row, unsigned int col) {
  std::queue<std::pair<unsigned int,unsigned int>> the_neighbours;
  // has northern neighbour?
  if(row > 0)
    the_neighbours.push(std::pair<unsigned int,unsigned int>(row-1,col));
  // has western neighbour?
  if (col > 0)
    the_neighbours.push(std::pair<unsigned int,unsigned int>(row,col-1));
  // has southern neighbour?
  if (row < fsrows-1)
    the_neighbours.push(std::pair<unsigned int,unsigned int>(row+1,col));
  // has eastern neighbour?
  if (col < fscols-1)
    the_neighbours.push(std::pair<unsigned int,unsigned int>(row,col+1));
  assert(!the_neighbours.empty());
  assert(the_neighbours.size() > 1);
  return the_neighbours;
}

bool Percolation::has_filled_neighbour(unsigned int row, unsigned int col) {
  assert(row < fsrows && col < fscols);
  std::queue<std::pair<unsigned int,unsigned int>> the_neighbours = examine_neighbours(row,col);
  while(!the_neighbours.empty()) {
    if (isFilled(the_neighbours.front()))
      return true;
    the_neighbours.pop();
  }
  return false;
}

void Percolation::examine_element(std::pair<unsigned int, unsigned int> coords) {
  std::queue<std::pair<unsigned int,unsigned int>> the_neighbours = examine_neighbours(coords);
  while(!the_neighbours.empty()) {
    if (isOpen(the_neighbours.front()))
      bag.push(the_neighbours.front()); // this may duplicate an element in bag.
    the_neighbours.pop();
  }
}

bool Percolation::percolates() {
  if (percolated)
    return true;
  if (bag.empty())
    return false;
  while(!bag.empty()) {
    if (isFilled(bag.front())) {
      bag.pop();
      continue;
    } 
    fill(bag.front());    
    if(bag.front().first == fsrows-1) {
      percolated = true;
      bag.pop();
      return true;
    }
    examine_element(bag.front());
    bag.pop();
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Percolation& pe) {
  std::cout << "size of outer: " << pe.f.size() << '\n';
  for (auto fit = pe.f.begin(); fit != pe.f.end(); ++fit) {
    for (auto fitit = fit->begin(); fitit != fit->end(); ++fitit) {
      std::cout << ' ' << *fitit;
    }
    std::cout << '\n';
  }
  return os;
}
