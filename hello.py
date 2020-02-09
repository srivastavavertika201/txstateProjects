import random
player_wins=0
computer_wins=0

def user_option():
	user_choice = input("Select Rock, Paper or Scissor: ")
	if user_choice in ("Rock","rock","r","R"):
		user_choice="r"
	elif user_choice in ("Paper","paper","p","P"):
		user_choice="p"
	elif user_choice in ("Scissor","scissor","s","S"):
		user_choice="s"
	else: print("I don't understand: Try Again!!")
	return user_choice

def comp_option():
	comp_choice = random.randint(1,3)
	if comp_choice == 1:
		comp_choice="r"
	elif comp_choice == 2:
		comp_choice="s"
	else: comp_choice="p"
	return comp_choice

while True:
	print("")
	user_choice=user_option()
	comp_choice=comp_option()
	if user_choice=="r":
		if comp_choice=="r":
			print("You chose Rock, Computer chose Rock : You tied!! ")
		elif comp_choice=="p":
			print("You chose Rock, Computer chose Paper : You lose!! ")
			computer_wins+=1
		elif comp_choice=="s":
			print("You chose Rock, Computer chose Scissor : You win!! ")
			player_wins+=1
	if user_choice=="s":
		if comp_choice=="s":
			print("You chose Scissor, Computer chose Scissor : You tied!! ")
		elif comp_choice=="r":
			print("You chose Scissor, Computer chose Rock : You lose!! ")
			computer_wins+=1
		elif comp_choice=="p":
			print("You chose Scissor, Computer chose Paper : You win!! ")
			player_wins+=1
	if user_choice=="p":
		if comp_choice=="p":
			print("You chose Paper, Computer chose Paper : You tied!! ")
		elif comp_choice=="s":
			print("You chose Paper, Computer chose Scissor : You lose!! ")
			computer_wins+=1
		elif comp_choice=="r":
			print("You chose Paper, Computer chose Rock : You win!! ")
			player_wins+=1
	print(" ")
	print("Player wins: "+str(player_wins))
	print("Computer wins: "+str(computer_wins))
	print(" ")
	
	user_choice = input("Do you want to play again? (Y/N)")
	if user_choice in ["Yes","yes","y","Y"]:
		pass
	elif user_choice in["No","no","N","n"]:
		break
	else: break
