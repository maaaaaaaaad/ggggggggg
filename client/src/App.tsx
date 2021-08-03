import React, { useEffect } from "react";
import { BrowserRouter } from "react-router-dom";
import { UserLoggedIn } from "./api/user/userLoggedIn";
import MediaQuery from "./MediaQuery";
import Navigators from "./navigators/Navigators";
import Routers from "./routes/Routers";

const App = () => {
  //

  const getSessionData = async () => {
    //
    const res = await UserLoggedIn();

    const userNickname: string = res.data.userSession.user?.nickname;
    console.log(userNickname ?? "Not logged in");
  };

  useEffect(() => {
    getSessionData();
  }, []);

  return (
    <MediaQuery>
      <BrowserRouter>
        <Navigators />
        <Routers />
      </BrowserRouter>
    </MediaQuery>
  );
};

export default App;
