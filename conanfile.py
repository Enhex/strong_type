from conans import ConanFile, tools


class StrongtypeConan(ConanFile):
	name = "strong_type"
	version = "master"
	license = "MIT"
	description = "Create new type from existing type without changing the interface."
	homepage = "https://github.com/Enhex/strong_type"
	exports_sources = "include/*"

	def package(self):
		self.copy("*.h")

	def package_id(self):
		self.info.header_only()