$args = ""
for i in 0..1000000
  $args += "hello "
end
  value = `echo #{$args}`
  puts value
