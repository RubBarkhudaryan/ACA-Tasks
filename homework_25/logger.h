#ifndef LOGGER_H

# define LOGGER_H

class Logger
{
	private:
		std::fstream	file;
		std::string		filename;
	public:
		Logger() = delete;
		Logger(const std::string& filename);
		~Logger();
		void						write(const std::string& message);
		void						write(const Matrix& matrix);
		void						replace_file(const std::string& new_filename);
		std::vector<std::string>	read();
	};

#endif