#include <unistd.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class CmdCtx {
public:
  CmdCtx() = delete;
  CmdCtx(const CmdCtx &other) = delete;
  CmdCtx(const std::vector<std::string> &cmd) : cmd_(cmd) {}
  char **BufArray();

private:
  std::vector<std::string> cmd_;
};

char **CmdCtx::BufArray() {
  char **array = new char *[cmd_.size() + 1];
  memcpy(array, cmd_.data(), sizeof(char *) * cmd_.size());
  array[cmd_.size()] = nullptr;
  return array;
}

int main() {
  std::string name;
  CmdCtx *ctx = new CmdCtx({"sudo", "docker", "top", "svc"});
  char **arr = ctx->BufArray();
  // execvp(arr[0], arr)
  std::getline(std::cin, name);
}
