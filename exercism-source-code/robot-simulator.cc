/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 *
 * @author F.de Sande
 * @date Jan 4, 2023
 * @brief ChatGPT solution to Robot Simulator Exercism problem
 *        * Problem description provided to ChatGPG (taken from the Exercism site):
            Write a C++ object oriented code for a robot simulator.
            A robot factory's test facility needs a program to verify robot movements.
            The robots have three possible movements:
            turn right
            turn left
            advance
            Robots are placed on a hypothetical infinite grid, facing a particular direction (north, east, south, or west) at 
            a set of {x,y} coordinates, e.g., {3,8}, with coordinates increasing to the north and east.
            The robot then receives a number of instructions, at which point the testing facility verifies the robot's new position, and in which direction it is pointing.
            The letter-string "RAALAL" means:
            Turn right
            Advance twice
            Turn left
            Advance once
            Turn left yet again
            Say a robot starts at {7, 3} facing north. Then running this stream of instructions should leave it at {9, 4} facing west.
 *
 * @see https://jutge.org/problems/P48713_en
 *      https://chat.openai.com/chat
 */

#include <iostream>
#include <string>
#include <unordered_map>

// Enum class representing the four directions
enum class Direction {
  kNorth,
  kEast,
  kSouth,
  kWest
};

// Struct representing a position on the grid
struct Position {
  int x;
  int y;
};

// Class representing a robot
class Robot {
 private:
  // The current position of the robot
  Position position_;
  // The current direction the robot is facing
  Direction direction_;

 public:
  // Constructs a new robot at the given position, facing the given direction
  Robot(int x, int y, Direction direction)
      : position_{x, y}, direction_(direction) {}

  // Turns the robot right
  void TurnRight() {
    switch (direction_) {
      case Direction::kNorth:
        direction_ = Direction::kEast;
        break;
      case Direction::kEast:
        direction_ = Direction::kSouth;
        break;
      case Direction::kSouth:
        direction_ = Direction::kWest;
        break;
      case Direction::kWest:
        direction_ = Direction::kNorth;
        break;
    }
  }

  // Turns the robot left
  void TurnLeft() {
    switch (direction_) {
      case Direction::kNorth:
        direction_ = Direction::kWest;
        break;
      case Direction::kWest:
        direction_ = Direction::kSouth;
        break;
      case Direction::kSouth:
        direction_ = Direction::kEast;
        break;
      case Direction::kEast:
        direction_ = Direction::kNorth;
        break;
    }
  }

  // Advances the robot by one step in the direction it is facing
  void Advance() {
    switch (direction_) {
      case Direction::kNorth:
        position_.y++;
        break;
      case Direction::kEast:
        position_.x++;
        break;
      case Direction::kSouth:
        position_.y--;
        break;
      case Direction::kWest:
        position_.x--;
        break;
    }
  }

  // Returns the current position of the robot
  const Position& GetPosition() const {
    return position_;
  }

  // Returns the current direction the robot is facing
  Direction GetDirection() const {
    return direction_;
  }
};

// Helper function to parse a string of instructions
std::unordered_map<char, void (Robot::*)()> ParseInstructions(
    const std::string& instructions) {
  std::unordered_map<char, void (Robot::*)()> parsed_instructions;
  for (char c : instructions) {
    switch (c) {
      case 'R':
        parsed_instructions[c] = &Robot::TurnRight;
        break;
      case 'L':
        parsed_instructions[c] = &Robot::TurnLeft;
        break;
      case 'A':
        parsed_instructions[c] = &Robot::Advance;
        break;
      default:
        throw std::invalid_argument("Invalid instruction: " + c);
    }
  }
  return parsed_instructions;
}

int main() {
  // Create a new robot at position {7, 3} facing north
  Robot robot(7, 3, Direction::kNorth);

  // Parse the instructions "RAALAL"
  std::unordered_map<char, void (Robot::*)()> instructions = ParseInstructions("RAALAL");
  for (const auto& [instruction, method] : instructions) {
    (robot.*method)();
  }

  // Print the final position and direction of the robot
  std::cout << "Final position: {" << robot.GetPosition().x << ", " << robot.GetPosition().y << "}" << std::endl;
  std::cout << "Final direction: " << static_cast<int>(robot.GetDirection()) << std::endl;

  return 0;
}
