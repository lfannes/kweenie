task :run do
	sh 'g++ -g main.cpp -o main'
	sh './main'
end