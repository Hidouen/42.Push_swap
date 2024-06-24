#!/usr/bin/ruby

if ARGV.length != 2
	puts "KO_test.rb: wrong number of arguments, requires 2 integers \n\t- usage: KO_test.rb [number of tests] [number of values]"
	exit 1
end

print "running make ...\n"
`make`
if	!$?.success?
	print "KO_test.rb: make failed\n"
	exit 1
end

if File.exist?("push_swap") == false || File.exist?("checker") == false
	print "KO_test.rb: push_swap or checker executable not found !\n"
	exit 1
end

working = ['|', '/', '-', '\\', '|', '/', '-', '\\']

for i in 1..ARGV[0].to_i
	print "running test #{i}/#{ARGV[0].to_i} ... #{working[i % working.length]}\r"
	$stdout.flush
	random_values = (-9999..9999).to_a.sample(ARGV[1].to_i).join(' ')
	results = `./push_swap #{random_values} | ./checker #{random_values}`
	if results.strip.upcase != "OK" && results.strip.upcase != ""
		puts "\n#{results.strip.upcase} with values:\n#{random_values}"
		exit 1
	end
end

puts "\nOK"
