task :new do 
	sh 'g++ main.cpp -o main'
	puts "Is het een bestaande file (y of n)?"
	answ = gets.strip
	if (answ == "y")
		puts "Welke file is het?"
		file1 = gets.strip
		Dir.chdir(file1) do
			puts "D
			ir.pwd"
		end
	end
	sh './main'
end