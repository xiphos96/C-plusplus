#include <string>

#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/compiler/command_line_interface.h>
#include <protoc-c/c_generator.h>

#define PACKAGE_STRING "SKYOS32"

int main(int argc, char* argv[]) {
  google::protobuf::compiler::c::CGenerator c_generator;

  std::string invocation_name = argv[0];
  std::string invocation_basename = invocation_name.substr(invocation_name.find_last_of("\\") + 1);
  const std::string legacy_name = "protoc.exe";
  const std::string legacy_name2 = "protoc";

  if (invocation_basename == legacy_name || invocation_basename == legacy_name2) {
    google::protobuf::compiler::CommandLineInterface cli;
    cli.RegisterGenerator("--c_out", &c_generator, "Generate C/H files.");
    cli.SetVersionInfo(PACKAGE_STRING);
    return cli.Run(argc, argv);
  }

  return google::protobuf::compiler::PluginMain(argc, argv, &c_generator);
}
