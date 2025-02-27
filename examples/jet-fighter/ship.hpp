#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "abcg.hpp"
#include "gamedata.hpp"

class OpenGLWindow;
class Bullets;

class Ship {
 public:
  void initializeGL(GLuint program, glm::vec2);
  void paintGL();
  void terminateGL();

  void update(const GameData &gameData, float deltaTime);
  void hit();

 private:
  friend OpenGLWindow;
  friend Bullets;

  GLuint gl_program{};
  GLuint gl_vao{};
  GLuint gl_vbo{};

  GLint ul_translation{};
  GLint ul_color{};
  GLint ul_scale{};
  GLint ul_rotation{};

  glm::vec4 color{0,0.5,1,1};
  float rotation{};
  float scale{0.04f};

  int player_number = 0;
  int life = 3;

  glm::vec2 translation{glm::vec2(0)};
  glm::vec2 velocity{glm::vec2(0)};

  bool isImmune = false;
  abcg::ElapsedTimer immunityTimer;
  abcg::ElapsedTimer bulletCoolDownTimer;
};
#endif
