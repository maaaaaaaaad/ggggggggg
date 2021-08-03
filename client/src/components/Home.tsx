import React from "react";
import { useContext } from "react";
import { ResUserDataContext } from "../App";

const Home = () => {
  const isUser = useContext(ResUserDataContext);

  return <section>Hello {isUser?.nickname}</section>;
};

export default Home;
