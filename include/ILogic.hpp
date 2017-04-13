//
//  ILogic.hpp
//  
//
//  Created by Vincent COUVERCHEL on 12/04/2017.
//
//

#ifndef ILogic_hpp
#define ILogic_hpp

#include <vector>
#include "Protocol.hpp"

typedef std::pair<size_t, void *> struct_info;

union Pixel {
  uint32_t	hexacode;
  char	rgba[4];
};

struct TileInfo {
  Pixel	color;
  const char	*filePath;
  uint32_t	spriteIndex;
};

struct Screen {
  size_t	width;
  size_t	height;
};

class ILogic {

public:
  virtual ~ILogic() {}
  virtual struct_info runCommand(arcade::CommandType type) = 0;
  virtual std::vector<TileInfo> const &getTiles() const = 0;
  virtual Screen const &getScreen() const = 0;
  virtual int const &getSpeed() const = 0;
};

typedef ILogic *(*func_logic)();

#endif /* ILogic_hpp */
