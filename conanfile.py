from conans import ConanFile, CMake, tools


class StrongtypeConan(ConanFile):
	name = "strong_type"
	version = "master"
	license = "MIT"
	description = "Create new type from existing type without changing the interface."
	# No settings/options are necessary, this is header only
	exports_sources = "include/*"

	def package(self):
		self.copy("*.h")