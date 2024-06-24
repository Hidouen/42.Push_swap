#!/usr/bin/ruby

if ARGV.length != 2
	puts "mean.rb: wrong number of arguments, requires 2 integers \n\t- usage: mean.rb [number of tests] [number of values]"
	exit 1
end

print "running make ...\n"
`make`
if	!$?.success?
	print "mean.rb: make failed\n"
	exit 1
end

if File.exist?("push_swap") == false
	print "mean.rb: push_swap executable not found !\n"
	exit 1
end

working = ['|', '/', '-', '\\', '|', '/', '-', '\\']

mean = 0;
min = -1;
max = -1;

for i in 1..ARGV[0].to_i
	print "running test #{i}/#{ARGV[0].to_i} ... #{working[i % working.length]}\r"
	$stdout.flush
	moves = `ARG=$(./random.rb -9999 9999 #{ARGV[1].to_i}) && ./push_swap $ARG | wc -l`.to_i
	if (moves > max)
		max = moves
	end
	if (moves < min || min == -1)
		min = moves
	end
	mean += moves;
end

mean = mean / ARGV[0].to_i

puts "\nmean = #{mean} average moves for #{ARGV[0].to_i} tests of #{ARGV[1].to_i} values"
puts "min = #{min.to_i} moves"
puts "max = #{max.to_i} moves"
